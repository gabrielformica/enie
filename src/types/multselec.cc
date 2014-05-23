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

Symbol* get_symbol() {
    return this->sym;
}

Exp* get_expression() {
    return this->expr;
}


void set_symbol(Symbol *s) {
    this->sym = s;
}

void set_expression(Exp *e) {
    this->expr = e;
}

bool check() {

    if (this->sym->type == this->expr->type) {
        return true;
    }

    return false;
}
