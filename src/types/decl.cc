/**
  * Copyright 2014
  *
  * @file selec.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for selection instruction type
  *
  */

#include <string>
#include "decl.hh"
#include "exp.hh"
#include "../symtable/symtable.hh"

Decl::Decl(Symbol *s, Exp *e) {
    this->sym = s;
    this->exp = e;
}


Symbol* Decl::getSymbol() {
    return this->sym;
}

Exp* Decl::getExpression() {
    return this->exp;
}


void Decl::setSymbol(Symbol *s) {
    this->sym = s;
}

void Decl::setExpression(Exp *e) {
    this->exp = e;
}

bool Decl::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
