#include <iostream>
#include <string>
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
