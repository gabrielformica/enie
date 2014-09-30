#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "parserhelper.hh"
#include "symtable/symtable.hh"
#include "symtable/symbol.hh"
#include "nodes/exp.hh"

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
        str += " columna " + to_string(symbol->getColumn()) + ") : ";
        str += "Funcion '" + symbol->getId() + "'";
        str += " fue declarada pero nunca implementada\n";
    }
    
    return str;
}
