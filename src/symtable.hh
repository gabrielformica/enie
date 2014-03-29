/*
 *  SymbolTable and Symbol Classes are defined here
 *
 */
#ifndef SYMTABLE_HH
#define SYMTABLE_HH
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <unordered_map>

/*
 * Symbols of the symbols table
 */

class Symbol {
  private:
    std::string id;
    int scope;
    int line;
    int column;
  public:
    Symbol(std::string,int,int,int);
}

/* Hash table for symbols */
typedef std::unordered_multimap<std::string,int> MapTable;


/*
 * Symbol table class
 */

class SymbolTable {
  private:
    int currentScope;
    MapTable table;    
    std::stack<int> scopeStack;
  public:
    SymTable();
    void enterScope();
    void leaveScope();
    int  getActualScope();
    Symbol lookup();
}
#endif
