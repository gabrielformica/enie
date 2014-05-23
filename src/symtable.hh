/*
 *  SymbolTable and Symbol Classes are defined here
 *
 */
#ifndef SYMTABLE_HH
#define SYMTABLE_HH
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

/*
 * Symbols of the symbol table
 */

class Symbol {
  private:
    std::string id;
    int scope;
    int line;
    int column;
    std::string type;
  public:
    explicit Symbol(std::string i, int s, int l, int c, std::string t = "") : 
             id(i), scope(s), line(l), column(c), type(t) {} 

    std::string getId();
    int getScope();
    int getLine();
    int getColumn();
    std::string getType();
    void setScope(int);
    void setLine(int);
    void setColumn(int);
    void print();
};

/* Hash table for symbols */
typedef std::unordered_multimap<std::string, Symbol *> MapTable;


/*
 * Symbol table class
 */

class SymbolTable {
  private:
    int scopeCounter;
    MapTable table;
    std::list<int> scopeStack;

  public:
    SymbolTable();
    void enterScope();
    void leaveScope();
    void addSymbol(Symbol *);
    int  getCurrentScope();
    Symbol *lookup(std::string, int);
    bool idIsInScope(std::string, int);
    bool isActive(Symbol *);
    void printStack();
    void printTable();
};
#endif
