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
    std::string getId();
    int getScope();
    int getLine();
    int getColumn();
    void setScope(int);
    void setLine(int);
    void setColumn(int);
};

/* Hash table for symbols */
typedef std::unordered_multimap<std::string,Symbol *> MapTable;


/*
 * Symbol table class
 */

class SymbolTable {
  private:
    int currentScope;
    MapTable table;
    std::stack<int> scopeStack;
  public:
    SymbolTable();
    void enterScope();
    void leaveScope();
    void addSymbol(Symbol *);
    int  getActualScope();
    Symbol *lookup(std::string, int);
};
#endif
