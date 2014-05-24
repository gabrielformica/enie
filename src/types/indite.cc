/**
  * Copyright 2014
  *
  * @file indite.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for intermined iteration instruction type
  *
  */

#include <string>
#include "indite.hh"
#include "exp.hh"
#include "../symtable.hh"

Symbol* Inedite::get_symbol() {
    return this->sym;
}

Exp* Inedite::get_expression() {
    return this->exp;
}


void Inedite::set_symbol(Symbol *s) {
    this->sym = s;
}

void Inedite::set_expression(Exp *e) {
    this->exp = e;
}

bool Inedite::check() {
    std::string exp_type = this->exp->check();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
