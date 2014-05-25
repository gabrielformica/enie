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


#include "multselec.hh"
#include "../symtable.hh"
#include "optlist.hh"

Multselec::Multselec(Symbol *s, Optlist *ol) {
    this->sym = s;
    this->optl = ol;
}


Symbol* Multselec::getSymbol() {
    return this->sym;
}

void Multselec::setSymbol(Symbol *s) {
    this->sym = s;
}

bool Multselec::check() {
    return true;
}
