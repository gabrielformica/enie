/**
  * Copyright 2014
  *
  * @file detite.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for determined iteration instruction type
  *
  */

#include <string>
#include "detite.hh"
#include "decl.hh"
#include "exp.hh"
#include "instbl.hh"

Exp* Detite::getExpression() {
    return this->exp;
}

Instbl* Detite::getBlock() {
    return this->block;
}

Decl* Detite::getDecl() {
    return this->declar;
}

bool Detite::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
