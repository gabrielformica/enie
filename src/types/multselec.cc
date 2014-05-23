/**
  * Copyright 2014
  *
  * @file multselec.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for case instruction type
  *
  */


#include "exp.hh"
#include "multselec.hh"
#include "../symtable.hh"

Symbol* Multselec::getSymbol() {
    return this->sym;
}

Exp* Multselec::getExpression() {
    return this->exp;
}


void Multselec::setSymbol(Symbol *s) {
    this->sym = s;
}

void Multselec::setExpression(Exp *e) {
    this->exp = e;
}

bool Multselec::check() {

    if (this->sym->getType() == this->exp->check()) {
        return true;
    }

    return false;
}
