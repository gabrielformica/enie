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


class Symbol {
    private:
        std::string id;
        std::string type;
        int scope;
        int line;
        int column;

    public:
        Symbol(std::string, std::string, int, int, int);
        Symbol(std::string, int, int, int);

        std::string getId();
        std::string getType();
        int getScope();
        int getLine();
        int getColumn();
        void setScope(int);
        void setLine(int);
        void setColumn(int);
        void setType(std::string);
        void print();
};

#endif
