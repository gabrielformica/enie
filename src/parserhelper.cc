#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "parserhelper.hh"
#include "symtable/symtable.hh"
#include "symtable/symbol.hh"
#include "nodes/exp.hh"
#include "interm_code/argument.hh"
#include "mips_code/mips_program.hh"

using namespace std;

void tryAddSymbol(SymbolTable *symtable, vector<string> *errors, Symbol *s) {
    std::string id = s->getId();
    int scope = s->getScope();
    int line = s->getLine();
    int column = s->getColumn();
    if (! symtable->idIsInScope(id, scope)) {
        symtable->addSymbol(s);
    }
    else {
        std::string str0 = "(linea "+ to_string(line)+ ", columna ";
        str0 += to_string(column) + "): ";
        std::string str = "error "+ str0 + "variable '"+ id +"'";
        str += ", ya fue declarada en este alcance";
        errors->push_back(str);
    }
}

std::vector<Type *> *getTypesFromExps(std::vector<Exp *> *exps) {
    std::vector<Type *> *types = new std::vector<Type *>;

    for (int i = 0; i < exps->size(); i++) {
        types->push_back((*exps)[i]->getType());
    }

    return types;
}

std::string chop(std::string str) {
    return "$t" + str.substr(2);
}

std::string catOffset(Symbol *s) {
    std::string str = std::to_string(s->getOffset()) + "($" + s->getId() + ")";
    return str;
}

/**
  * Returns the errors given by declared functions that were not implemented
  */

std::string not_implemented(SymbolTable *symtable) {
    std::list<Symbol *> *functions = symtable->getStillForwards();
    std::string str = "";
    for (std::list<Symbol *>::iterator it = functions->begin();
                             it != functions->end(); ++it) {

        Symbol *symbol = *(it);

        str += "error ";
        str += "(linea " + to_string(symbol->getLine());
        str += ", columna " + to_string(symbol->getColumn()) + "): ";
        str += "funcion '" + symbol->getId() + "'";
        str += " fue declarada pero nunca implementada\n";
    }

    return str;
}


void mainLW(SymbolTable *symtable, Symbol *reg, Symbol *b) {
    std::vector<Symbol *> *vars = reg->getVars();
    reg->initializeVars();
    if (b!= NULL) {
        reg->getVars()->push_back(b);
    }
    for (std::vector<Symbol *>::iterator it=vars->begin(); it!=vars->end(); ++it) {
        Symbol *s = (*it);
        int i = 0;
        for (std::vector<Symbol *>::iterator vit=s->getVars()->begin(); vit!=s->getVars()->end(); ++vit) {
            if ((*vit) == reg) {
                break;
            }
            i++;
        }
        s->getVars()->erase(s->getVars()->begin() + i);
    }
}


void mainSW(Symbol *b) {
    b->getVars()->push_back(b);
}

/* getReg */
void getReg(Quad *inst, SymbolTable *symtable, MipsProgram *program) {
    //if quad is  z = x op y

    if (inst->zxy()) {
        // Get register and add instructions of x operands of the quad
        // The second argument is the symbol to ignore when looking for
        // registers.

        Symbol *x = getRegAux(inst->getArg1(), NULL, symtable, program);

        if (inst->getOp() == "+") {
            if (inst->getArg2()->is("ArgumentVar")) {
                Symbol *y = getRegAux(inst->getArg1(), x, symtable, program);
                Add *add = new Add(chop(x->getId()), chop(x->getId()), chop(y->getId()));
                program->addInst(add);
                mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
            } else {
                AddI *addi = new AddI(chop(x->getId()), chop(x->getId()), ((ArgumentConst *)(inst->getArg2()))->getElem());
                program->addInst(addi);
                mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
            }
        } else if (inst->getOp() == "-") {
            Symbol *y = getRegAux(inst->getArg1(), x, symtable, program);
            Sub *sub = new Sub(chop(x->getId()), chop(x->getId()), chop(y->getId()));
            program->addInst(sub);
                mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
            program->addInst(sub);
        } else if (inst->getOp() == "*") {
            Symbol *y = getRegAux(inst->getArg1(), x, symtable, program);
            Mult *mult = new Mult(chop(x->getId()), chop(y->getId()));
            program->addInst(mult);

            Mflo *mflo = new Mflo(chop(x->getId()));
            program->addInst(mflo);

            mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
        } else if (inst->getOp() == "/") {
            Symbol *y = getRegAux(inst->getArg1(), x, symtable, program);
            Div *divi = new Div(chop(x->getId()), chop(y->getId()));
            program->addInst(divi);

            Mflo *mflo = new Mflo(chop(x->getId()));
            program->addInst(mflo);
            mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
        } else if (inst->getOp() == "%") {
            Symbol *y = getRegAux(inst->getArg1(), x, symtable, program);
            Div *divi = new Div(chop(x->getId()), chop(y->getId()));
            program->addInst(divi);

            Mfhi *mfhi = new Mfhi(chop(x->getId()));
            program->addInst(mfhi);
            mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());
        }
        //arg1 is not in x
    } else if (inst->isCopy()) {  //x = y
        Symbol *s = getRegAux(inst->getArg1(), NULL, symtable, program);
        program->addInst(new Sw(chop(s->getId()), catOffset(((ArgumentVar *) inst->getResult())->getSymbol()))); //x has the value of y
        Symbol *x = ((ArgumentVar *) inst->getResult())->getSymbol();
        x->initializeVars();
        mainLW(symtable, x, s);     //buscar todos los registros que tenian a x y eliminarlos
        x->getVars()->push_back(s); //agregar que X esta en el nuevo registro s
    }

}


/* getRegAux:   reg is the register that can't be used */
Symbol *getRegAux(Argument *arg, Symbol *dont_use,
                    SymbolTable *symtable,
                    MipsProgram *program) {


    Symbol *reg_to_use;
    if (arg->is("ArgumentVar")) {
        Symbol *s = ((ArgumentVar *) arg)->getSymbol();

        if (! symtable->inReg(s)) {
            reg_to_use = symtable->getFreeReg(dont_use);
            if (reg_to_use == NULL) {
                reg_to_use = symtable->getRandomReg(dont_use);
                store_them(reg_to_use, program);
            }
        } else {
            reg_to_use = s->getRegToUse();
        }

        Lw *lw = new Lw(catOffset(((ArgumentVar *)arg)->getSymbol()), chop(reg_to_use->getId()));
        program->addInst(lw);
        mainLW(symtable, reg_to_use, ((ArgumentVar *)arg)->getSymbol());
    } else if (arg->is("ArgumentConst")) {
        reg_to_use = symtable->getFreeReg(dont_use);
        if (reg_to_use == NULL) {
            reg_to_use = symtable->getRandomReg(dont_use);
            store_them(reg_to_use, program);
        }
        Lw *lw = new Lw(((ArgumentConst *)arg)->getElem(), chop(reg_to_use->getId()));
        // mantener registros
        mainLW(symtable, reg_to_use, NULL);
        program->addInst(lw);
    }

    return reg_to_use;
}

void store_them(Symbol *reg, MipsProgram *program) {
    std::vector<Symbol *> *store_list = reg->getVars();
    for (std::vector<Symbol *>::iterator it=store_list->begin();
                                         it!=store_list->end();
                                         ++it) {
        Sw *sw = new Sw( chop(reg->getId()), catOffset((*it)) );
        program->addInst(sw);
        mainSW((*it));
    }
}


void addRegisters(SymbolTable *symtable, Type *t) {
    for (int i = 0; i < 7; ++i) {
        std::string name = "R_" + std::to_string(i);

        symtable->addSymbol(new Symbol(name, t, -1, -1, -1));
    }
}
