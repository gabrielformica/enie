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
#include "exp.hh"
#include "../symtable.hh"

Symbol* Selec::get_symbol() {
    return this->sym;
}

Exp* Selec::get_expression() {
    return this->exp;
}


void Selec::set_symbol(Symbol *s) {
    this->sym = s;
}

void Selec::set_expression(Exp *e) {
    this->exp = e;
}

bool Selec::check() {
    std::string exp_type = this->exp->check();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
