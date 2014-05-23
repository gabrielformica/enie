/**
  * Copyright 2014
  *
  * @file asign.cc
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

#include "asign.hh"

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
    std::string exp_type = this->expr->check();
    std::string sym_type = this->expr->get_type();

    if (sym_type == exp_type) {
        return true;
    }

    return false;
}
