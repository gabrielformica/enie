/**
  * Copyright 2014
  *
  * @file
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * SymbolTable class implementation (LeBlanc-Cook symbol table)
  */


#include <iostream>
#include <string>
#include <unordered_map>
#include "symtable.hh"
#include "symbol.hh"

using namespace std;


/** Class constructor*/

SymbolTable::SymbolTable() {
    this->scopeCounter = 0;
    this->table = {};
    this->scopeStack.push_back(0);  // first scope is 0
}

/* Add new scope*/

void SymbolTable::enterScope() {
    int cs = ++this->scopeCounter;
    this->scopeStack.push_back(cs);
}

/* Leave scope*/

void SymbolTable::leaveScope() {
    this->scopeStack.pop_back();
}

/* Return scope of the program */

int SymbolTable::getCurrentScope() {
    return this->scopeStack.back();
}

/* Add symbol to symbol table*/

void SymbolTable::addSymbol(Symbol *s) {
    string id = s->getId();
    if (!this->idIsInScope(s->getId(),s->getScope())) {
        this->table.insert(MapTable::value_type(id, s));
    }
}

/* Tell if id is already in scope */
bool SymbolTable::idIsInScope(string id, int scope) {
    return lookup(id, scope) != NULL;
}

/* Tell if a symbol declaration is active */

bool SymbolTable::isActive(Symbol *s) {
    for (list<int>::reverse_iterator it = this->scopeStack.rbegin();
                                     it != this->scopeStack.rend(); ++it) {

        if (this->idIsInScope(s->getId(), *it))
            return true;

    }
    return false;
}

/* look up the symbol */

Symbol *SymbolTable::lookup(string id, int scope) {
    auto its = this->table.equal_range(id);
    for (auto it = its.first; it != its.second; ++it) {
        if (scope == it->second->getScope()) {
            return it->second;
        }
    }
    return NULL;
}

void SymbolTable::printStack() {
    cout << "STACK" << endl;
    for (list<int>::reverse_iterator it = this->scopeStack.rbegin();
            it != this->scopeStack.rend(); ++it) {
        cout << *it << endl;
    }
    cout << "STACK" << endl;
}

void SymbolTable::printTable() {
    std::cout << "-----Tabla de simbolos-----" << std::endl;
    std::cout << endl;

    for (MapTable::iterator it = table.begin(); it != table.end(); it++ ) {
        (*it).second->print();
    }
}
