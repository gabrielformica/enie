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
#include "selec.hh"

Symbol* Selec::get_symbol() {
    return this->sym;
}

Exp* Selec::get_expression() {
    return this->expr;
}


void Selec::set_symbol(Symbol *s) {
    this->sym = s;
}

void Selec::set_expression(Exp *e) {
    this->expr = e;
}

bool Selec::check() {
    std::string exp_type = this->expr->check();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
