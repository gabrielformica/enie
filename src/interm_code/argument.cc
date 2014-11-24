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
  * Class definitions for arguments
  */

#include "argument.hh"

Type *Argument::getType() { return this->type; }

ArgumentVar::ArgumentVar(Symbol *var, Type *t) {
    this->var = var;
    this->type = t;
}

bool ArgumentVar::is(std::string str) { return str == "ArgumentVar"; }
std::string ArgumentVar::toString() { return this->var->getId(); }
Symbol *ArgumentVar::getSymbol() { return this->var; }

ArgumentConst::ArgumentConst(std::string elem, Type *t) {
    this->elem = elem;
    this->type = t;
}

bool ArgumentConst::is(std::string str) { return str == "ArgumentConst"; }
std::string ArgumentConst::toString() { return this->elem; }

std::string ArgumentConst::getElem() { return this->elem; }
