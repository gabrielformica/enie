#include <iostream>
#include <string>
#include <unordered_map>
#include "symtable.hh"

using namespace std;


/*
 ************************************
 * Symbols class methods definitions*
 ************************************
 */


/* Class constructor*/

Symbol::Symbol(string id, int scope, int line, int column) {
    this->id = id;
    this->scope = scope;
    this->line = line;
    this->column = column;
}

/* Return id of the symbol */

string Symbol::getId() {
    return this->id;
}

/* Return scope of the symbol*/

int Symbol::getScope() {
    return this->scope;
}

/* Return line of the symbol*/

int Symbol::getLine() {
    return this->line;
}

/* Return column of the symbol*/

int Symbol::getColumn() {
    return this->column;
}

/* Set scope*/

void Symbol::setScope(int x) {
    this->scope = x;
}

/* Set line*/
void Symbol::setLine(int x) {
    this->line = x;
}

/* Set column*/
void Symbol::setColumn(int x) {
    this->column = x;
}

/*
 ****************************************
 * SymbolTable class methods definitions*
 ****************************************
 */


/* Class constructor*/
SymbolTable::SymbolTable() {
    this->currentScope = 0;
    this->table = {};
    this->scopeStack.push(0);  //first scope is 0
}

/* Add new scope*/

void SymbolTable::enterScope() {
    int cs = ++this->currentScope;
    this->scopeStack.push(cs);
}

/* Leave scope*/

void SymbolTable::leaveScope() {
    this->scopeStack.pop();
}

/* Return scope of the program */

int SymbolTable::getActualScope() {
    return this->scopeStack.top();
}

/* Add symbol to symbol table*/

void SymbolTable::addSymbol(Symbol *s) {
    string id = s->getId();
    this->table.insert(MapTable::value_type(id,s));
}

/* look up the symbol */

Symbol *SymbolTable::lookup(string id, int scope) {
    auto its = this->table.equal_range(id);
    for (auto it = its.first; it != its.second; ++it) {
        if (scope == it->second->getScope()) {
            return it->second;
        }
    } 
}