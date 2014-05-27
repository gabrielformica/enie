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


#include <string>
#include "symbol.hh"
#include "func_symbol.hh"


/** Class constructor */

FuncSymbol::FuncSymbol(std::string id, 
                       int scope, int line, int column, bool forwarded
                       ) : Symbol(id, "@function", scope, line, column) {

    this->forwarded = forwarded;
}

bool FuncSymbol::isForwarded() {
    return this->forwarded;
}

