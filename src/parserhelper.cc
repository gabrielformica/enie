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

/* getReg */

void getReg(Quad *inst, SymbolTable *symtable) {
    //if quad is  z = x op y 
    if (inst->zxy()) {  
        Symbol *x = getRegAux(inst->getArg1(), NULL, symtable);
        Symbol *y = getRegAux(inst->getArg1(), x, symtable);
    }
}


/* getRegAux:   reg is the register that can't be used */
Symbol *getRegAux(Argument *arg, Symbol *dont_use, SymbolTable *symtable) {
    if (arg->is("ArgumentVar")) {
        Symbol *s = ((ArgumentVar *) arg)->getSymbol();
        if (! symtable->inReg(s)) {
            Symbol *reg_to_use = symtable->getFreeReg(dont_use);
            if (reg_to_use == NULL) {
                reg_to_use = symtable->getRandomReg(dont_use);
                store_them(reg_to_use);
            }
        }
        //LW arg->getSymbol()->getId()  reg
    }
}

void store_them(Symbol *reg) {
    std::vector<Symbol *> *store_list = reg->getVars();
    for (std::vector<Symbol *>::iterator it=store_list->begin(); 
                                         it!=store_list->end();
                                         ++it) {
        //new StoreWord( (*it), s)  
        //Add them to the global vector 
    }
}
