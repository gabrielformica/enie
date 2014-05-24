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
#include <list>
#include "selec.hh"
#include "oselec.hh"
#include "exp.hh"

Exp* Selec::getExpression() {
    return this->exp;
}

Oseleclist* Selec::getList() {
    return this->oselecList;
}

bool Selec::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
