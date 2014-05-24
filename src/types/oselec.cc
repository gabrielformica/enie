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
#include "exp.hh"

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
