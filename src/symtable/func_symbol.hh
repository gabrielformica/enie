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
  * FuncSymbol class definition
  */


#ifndef FUNC_SYMBOL_HH 
#define FUNC_SYMBOL_HH 

#include <string>
#include "symbol.hh"

class FuncSymbol: public Symbol {
    private:
        bool forwarded;
    public:
        FuncSymbol(std::string, std::string, int, int, int, bool);
        bool isForwarded();
};

#endif
