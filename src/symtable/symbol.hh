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
#include <unordered_map>
#include "../sound_type_system/base/type.hh"


class Symbol {
    private:
        std::string id;
        Type *type;
        int scope;
        int line;
        int column;

    public:
        Symbol(std::string id, Type *t, int s, int l, int c);
        Symbol(std::string, int, int, int);


        std::string getId();
        Type *getType();
        int getScope();
        int getLine();
        int getColumn();
        void setScope(int);
        void setLine(int);
        void setColumn(int);
        void setType(Type*);
        void print();
};

#endif
