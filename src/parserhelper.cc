#include <iostream>
#include <string>
#include <vector>
#include "parserhelper.hh"

using namespace std;

void tryAddSymbol(SymbolTable *symtable, vector<string> *errors, Symbol *s) {
    std::string id = s->getId();
    int scope = s->getScope();
    int line = s->getLine();
    int column = s->getColumn();
    if (! symtable->idIsInScope(id, scope)) {
        symtable->addSymbol(s);
        cout << "El simbolo " << id << " esta en la linea : " << line << endl;
    }
    else {
        std::string str0 = "(linea "+ to_string(line)+ ", columna ";
        str0 += to_string(column) + "): ";
        std::string str = "error "+ str0 + "variable '"+ id +"'";
        str += ", ya fue declarada en este alcance";
        errors->push_back(str);
    }
}

void checkUse(SymbolTable *symtable, vector<string> *errors, Symbol *s) {
    if (! symtable->isActive(s)) {
        std::string id = s->getId();
        int line = s->getLine();
        int column = s->getColumn();
        std::string str0 = "(linea "+ to_string(line)+ ", columna ";
        str0 += to_string(column) + "): ";
        std::string str = "error "+ str0 + "variable '"+ id +"'";
        str += ", no ha sido declarada";
        errors->push_back(str);
    }
}
