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
#include "instbl.hh"

Exp* Inedite::getExpression() {
    return this->exp;
}

Instbl* Inedite::getBlock() {
    return this->block;
}

bool Inedite::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
