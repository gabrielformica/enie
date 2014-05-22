/**
  * Copyright 2014
  *
  * @file ent.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for integer type
  *
  */

#include "ent.hh"

Ent::Ent(int v) {
    this->val = v;
}

int get_ent() {
    return this->val;
}

void set_ent(int v) {
    this->val = v;
}
