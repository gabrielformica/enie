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
#include "../symtable.hh"

Symbol* Decl::get_symbol() {
    return this->sym;
}

Exp* Decl::get_expression() {
    return this->exp;
}


void Decl::set_symbol(Symbol *s) {
    this->sym = s;
}

void Decl::set_expression(Exp *e) {
    this->exp = e;
}

bool Decl::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
