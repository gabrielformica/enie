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
  * Symbol class definition
  */


#ifndef SYMBOL_HH
#define SYMBOL_HH
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include "../sound_type_system/base/type.hh"


class Symbol {
    private:
        std::string id;
        Type *type;
        int scope;
        int line;
        int column;
        int offset = 0;
        std::vector<Symbol *> *vars;

    public:
        Symbol(std::string id, Type *t, int s, int l, int c);
        Symbol(std::string, int, int, int);
        Symbol(std::string id, Type *t, int s, int l, int c, int o);


        std::string getId();
        Type *getType();
        int getScope();
        int getLine();
        int getColumn();
        void setScope(int);
        void setLine(int);
        void setColumn(int);
        void setType(Type*);
        int getOffset();
        void setOffset(int);
        void print();
        std::vector<Symbol *> *getVars();
        void initializeVars();
        Symbol *getRegToUse();
};

#endif
