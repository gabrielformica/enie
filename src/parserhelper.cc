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
        if (! symtable->IdIsInScope(id, scope)) {
           symtable->addSymbol(s);
           cout << "El simbolo " << id << " esta en la linea : " << line << endl;
        }
        else {
           std::string str = "variable '"+ id + "' redeclarada ";
           str+= "en linea :"+ to_string(line);
           errors->push_back(str);
        }
}
