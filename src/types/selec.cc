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

Selec::Selec(Exp *e, Instbl *bl, Oseleclist *l) {
    this->exp = e;
    this->block = bl;
    this->list = l;
}


Exp* Selec::getExpression() {
    return this->exp;
}

void Selec::initList(Oselec *os) {
    this->list = new Oseleclist(os);
}

Oseleclist* Selec::getList() {
    return this->list;
}

bool Selec::check() {
    std::string exp_type = this->exp->getType();

    if (exp_type == "bool") {
        return true;
    }

    return false;
}
