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


/*Return scope of the symbol*/

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

void Symbol:: setScope(int x) {
    this->scope = x;
}

/* Set line*/
void Symbol:: setLine(int x) {
    this->line = x;
}

/* Set column*/
void Symbol:: setColumn(int x) {
    this->column = x;
}

/*
 ****************************************
 * SymbolTable class methods definitions*
 ****************************************
 */


/* Add new scope*/

void SymbolTable::enterScope() {
    int cs = this->currentScope++;
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

/* look up the symbol */

Symbol *SymbolTable::lookup(string id, int scope) {
    auto its = this->table.equal_range(id);
    for (auto it = its.first; it != its.second; ++it) {
        if scope == it->second.getScope() {
            return &it->second;
        }
    } 
}
