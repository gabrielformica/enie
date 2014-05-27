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

Indite::Indite(Exp *e, Instbl *bl) {
    this->exp = e;
    this->block = bl;
}

Exp* Indite::getExpression() {
    return this->exp;
}

Instbl* Indite::getBlock() {
    return this->block;
}

bool Indite::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
