/**
  * Copyright 2014
  *
  * @file option.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementation for the options of a case instruction
  *
  */

#include <string>
#include "option.hh"
#include "../symtable.hh"
#include "instbl.hh"

Option::Option(Instbl *bl, bool is, Symbol *s, std::string c) {
    if (is) {
        this->sym = NULL;
        this->cad = c;
    } else {
        this->sym = s;
        this->cad = "";
    }

    this->block = bl;
}

Option::Option(std::string c) {
    this->sym = NULL;
    this->block = NULL;
    this->cad = c;
}


Option::Option(Symbol *s) {
    this->sym = s;
    this->block = NULL;
    this->cad = "";
}

void Option::setBlock(Instbl *bl) {
    this->block = bl;
}


