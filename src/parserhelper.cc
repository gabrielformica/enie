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
    std::string str = std::to_string(s->getOffset()) + "(sp)";
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


void mainLW(SymbolTable *symtable, Symbol *a, Symbol *b) {
    std::set<Symbol *> *vars = a->getVars();

    for (std::set<Symbol *>::iterator it=vars->begin(); it!=vars->end();
        it++) {

        std::set<Symbol *> *vars2 = (*it)->getVars();

        std::set<Symbol *>::iterator val = vars2->find(a);
        if (val != vars2->end())
            vars2->erase(val);

        vars->erase(it);
    }

    // vars->insert(b);

    // reg->initializeVars();
    // for (std::set<Symbol *>::iterator it=vars->begin(); it!=vars->end(); ++it) {
    //     Symbol *s = (*it);
    //     int i = 0;
    //     for (std::set<Symbol *>::iterator vit=s->getVars()->begin(); vit!=s->getVars()->end(); vit++) {
    //         std::cout << "Comparando:";
    //         std::cout << (*vit)->getId();
    //         std::cout << " con:";
    //         std::cout << reg->getId();
    //         std::cout << std::endl;
    //         if ((*vit) == reg) {
    //             break;
    //         }
    //         i++;
    //     }
    //     std::cout << "i es:";
    //     std::cout << i << std::endl;
    //     std::cout << "Size vector: ";
    //     std::cout << s->getVars()->size() << std::endl;

    //     std::cout << "Symbol: ";
    //     std::cout << s->getId() << std::endl;

    //    // symtable->printTable();

    //     // s->getVars()->erase(s->getVars()->begin() + i);
    // }
    // if (b!= NULL) {
    //     reg->getVars()->push_back(b);
    //     b->getVars()->push_back(reg);
    // }
}


void mainSW(Symbol *b) {
    b->getVars()->insert(b);
}

/* getReg */
void getReg(Quad *inst, SymbolTable *symtable, MipsProgram *program) {
    //if quad is  z = x op y
    // symtable->printTable();
    // std::cout << program->emit() << std::endl;

    if (inst->zxy()) {
        // Get register and add instructions of x operands of the quad
        // The second argument is the symbol to ignore when looking for
        // registers.

        Symbol *x = getRegAux(inst->getArg1(), NULL, symtable, program);

        if (inst->getArg1()->is("ArgumentConst")) {
            Li *li = new Li(chop(x->getId()), ((ArgumentConst*)inst->getArg1())->getElem());
            program->addInst(li);
        } else {
            if (((ArgumentVar *)inst->getArg1())->getSymbol()->getId().substr(0, 1) == "$") {
        //       Lw *lw = new Lw(chop(x->getId()), catOffset(((ArgumentVar*)inst->getArg1())->getSymbol()));
        //        program->addInst(lw);
        // mainLW(symtable, ((ArgumentVar*)inst->getArg1())->getSymbol(), x);
        // mainLW(symtable, x,((ArgumentVar*)inst->getArg1())->getSymbol());
            } else {
                Lw *lw = new Lw(chop(x->getId()), ((ArgumentConst*)inst->getArg1())->getElem());
                program->addInst(lw);
            }
        }

        if (inst->getOp() == "+") {
            if (inst->getArg2()->is("ArgumentVar")) {
                Symbol *y = getRegAux(inst->getArg2(), x, symtable, program);
                Add *add = new Add(chop(x->getId()), chop(x->getId()), chop(y->getId()));
                program->addInst(add);

                mainLW(symtable, x, x);
                std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
                vars->clear();
                vars->insert(x);

                x->getVars()->clear();
                x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

                mainLW(symtable, y, y);
                y->getVars()->clear();

            } else {
                AddI *addi = new AddI(chop(x->getId()), chop(x->getId()), ((ArgumentConst *)(inst->getArg2()))->getElem());
                program->addInst(addi);

                mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());

                std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
                vars->clear();
                vars->insert(x);
                x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

                // mainLW(symtable, ((ArgumentVar *)inst->getResult())->getSymbol(), x);
            }
        } else if (inst->getOp() == "-") {
            // if (inst->getArg2()->is("ArgumentVar")) {
                Symbol *y = getRegAux(inst->getArg2(), x, symtable, program);
                Sub *sub = new Sub(chop(x->getId()), chop(x->getId()), chop(y->getId()));
                program->addInst(sub);

                mainLW(symtable, x, x);
                std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
                vars->clear();
                vars->insert(x);

                x->getVars()->clear();
                x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

                mainLW(symtable, y, y);
                y->getVars()->clear();

            // } else {
            //     AddI *addi = new AddI(chop(x->getId()), chop(x->getId()), ((ArgumentConst *)(inst->getArg2()))->getElem());
            //     program->addInst(addi);

            //     mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());

            //     std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
            //     vars->clear();
            //     vars->insert(x);
            //     x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

            //     // mainLW(symtable, ((ArgumentVar *)inst->getResult())->getSymbol(), x);
            // }
        } else if (inst->getOp() == "*") {
            // if (inst->getArg2()->is("ArgumentVar")) {
                Symbol *y = getRegAux(inst->getArg2(), x, symtable, program);
                Mult *mult = new Mult(chop(x->getId()), chop(y->getId()));
                program->addInst(mult);

                Mfhi *mfhi = new Mfhi(chop(x->getId()));
                program->addInst(mfhi);

                mainLW(symtable, x, x);
                std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
                vars->clear();
                vars->insert(x);

                x->getVars()->clear();
                x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

                mainLW(symtable, y, y);
                y->getVars()->clear();

            // } else {
            //     AddI *addi = new AddI(chop(x->getId()), chop(x->getId()), ((ArgumentConst *)(inst->getArg2()))->getElem());
            //     program->addInst(addi);

            //     mainLW(symtable, x, ((ArgumentVar *)inst->getResult())->getSymbol());

            //     std::set<Symbol *> *vars = ((ArgumentVar *)inst->getResult())->getSymbol()->getVars();
            //     vars->clear();
            //     vars->insert(x);
            //     x->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());

                // mainLW(symtable, ((ArgumentVar *)inst->getResult())->getSymbol(), x);
            // }
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

        // LHS is a temp
        if (((ArgumentVar *)inst->getResult())->getSymbol()->getId().substr(0, 1) == "$") {
            Symbol *y = getRegAux(inst->getArg1(), NULL, symtable, program);
            Lw *lw = new Lw(chop(y->getId()), catOffset(((ArgumentVar*)inst->getArg1())->getSymbol()));
            program->addInst(lw);

            y->getVars()->insert(((ArgumentVar *)inst->getResult())->getSymbol());
            y->getVars()->insert(((ArgumentVar *)inst->getArg1())->getSymbol());

            ((ArgumentVar *)inst->getResult())->getSymbol()->getVars()->insert(y);
            ((ArgumentVar *)inst->getArg1())->getSymbol()->getVars()->insert(y);

            // mainLW(symtable, ((ArgumentVar*)inst->getResult())->getSymbol(), y);
            // mainLW(symtable, y, ((ArgumentVar*)inst->getResult())->getSymbol());

        } else { // LHS is a variable
            if (inst->getArg1()->is("ArgumentConst")) { // RHS is constant
                Symbol *s = getRegAux(inst->getArg1(), NULL, symtable, program);
                Li *li = new Li(chop(s->getId()), ((ArgumentConst*)inst->getArg1())->getElem());
                program->addInst(li);
                Sw *sw = new Sw(catOffset(((ArgumentVar*)inst->getResult())->getSymbol()), chop(s->getId()));
                program->addInst(sw);
            } else {
                Symbol *s = getRegAux(inst->getArg1(), NULL, symtable, program);

                s->getVars()->clear();
                ((ArgumentVar *)inst->getArg1())->getSymbol()->getVars()->clear();


                // mainLW(symtable, s, ((ArgumentVar*)inst->getArg1())->getSymbol());
                // mainLW(symtable, ((ArgumentVar*)inst->getArg1())->getSymbol(), s);
                //Lw *lw = new Lw(chop(s->getId()), ((ArgumentConst*)inst->getArg1())->getElem());
                Sw *sw = new Sw(catOffset(((ArgumentVar*)inst->getResult())->getSymbol()), chop(s->getId()));
                //program->addInst(lw);
                program->addInst(sw);
            }
        }


        // Symbol *s = getRegAux(inst->getArg1(), NULL, symtable, program);
        // program->addInst(new Sw(chop(s->getId()), catOffset(((ArgumentVar *) inst->getResult())->getSymbol()))); //x has the value of y
        // Symbol *x = ((ArgumentVar *) inst->getResult())->getSymbol();
        // // x->initializeVars();

        // std::cout << "---++++iii" << std::endl;
        // std::cout << s->getId() << std::endl;
        // std::cout << x->getId() << std::endl;
        // symtable->printTable();
        // std::cout << "---++++iii" << std::endl;
        // mainLW(symtable, x, s);     //buscar todos los registros que tenian a x y eliminarlos
    }

}


/* getRegAux:   dont_use is the register that can't be used */
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

        // Lw *lw = new Lw(catOffset(((ArgumentVar *)arg)->getSymbol()), chop(reg_to_use->getId()));
        // program->addInst(lw);
        mainLW(symtable, reg_to_use, ((ArgumentVar *)arg)->getSymbol());
    } else if (arg->is("ArgumentConst")) {
        reg_to_use = symtable->getFreeReg(dont_use);
        if (reg_to_use == NULL) {
            reg_to_use = symtable->getRandomReg(dont_use);
            store_them(reg_to_use, program);
        }

        // Lw *lw = new Lw(((ArgumentConst *)arg)->getElem(), chop(reg_to_use->getId()));
        // mantener registros
        // mainLW(symtable, reg_to_use, NULL);
        // program->addInst(lw);
    }

    return reg_to_use;
}

void store_them(Symbol *reg, MipsProgram *program) {
    // FLAG
    std::cout << "ENTRO EN STORE_THEM" << std::endl;

    std::set<Symbol *> *store_list = reg->getVars();
    for (std::set<Symbol *>::iterator it=store_list->begin();
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
