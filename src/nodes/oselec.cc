/**
  * Copyright 2014
  *
  * @file oselec.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for selection's else if instruction type
  *
  */

#include <string>
#include "oselec.hh"
#include "instbl.hh"
#include "exp.hh"

Oselec::Oselec(Exp *e, Instbl *bl) {
    this->exp = e;
    this->block = bl;
}

Exp* Oselec::getExpression() {
    return this->exp;
}

Instbl* Oselec::getBlock() {
    return this->block;
}

bool Oselec::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
