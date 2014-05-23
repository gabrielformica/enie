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
  * Class definitions for asignment instruction type
  *
  */

#include "selec.hh"

Symbol* get_symbol() {
    return this->sym;
}

// Expression* get_expression() {
//     return this->expr;
// }


void set_symbol(Symbol *s) {
    this->sym = s;
}

// void set_expression(Expression *e) {
//     this->expr = e;
// }

bool check() {
    if (this->sym->type == this->expr->type) {
        return true;
    }

    return false;
}
