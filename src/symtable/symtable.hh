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
  * SymbolTable class definition (LeBlanc-Cook symbol table)
  */


#ifndef SYMTABLE_HH
#define SYMTABLE_HH
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include "symbol.hh"
#include "../sound_type_system/base/cadena.hh"


typedef std::unordered_multimap<std::string, Symbol *> MapTable;

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
        Symbol *getSymbolInScope(std::string, int);
        Symbol *lookup(std::string);
        Symbol *getSymbol(std::string);
        bool idIsInScope(std::string, int);
        bool isActive(std::string);
        void printStack();
        void printTable();
        std::list<Symbol *> *getAllSymbols();
        std::list<Symbol *> *getStillForwards();
        std::vector<std::string> *getAllStrings();
};

#endif
