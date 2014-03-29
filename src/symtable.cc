#include <iostream>
#include <string>
#include "symtable.hh"

using namespace std;

/*
 * Add new scope
 */

void SymbolTable::enterScope() {
    int cs = this->currentScope++;
    this->scopeStack.push(cs);
}

/*
 * Return scope of the program
 */

int SymbolTable::getActualScope() {
    return this->scopeStack.top();
}


