/**
  * Copyright 2014
  *
  * @file flot.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for floating point type
  *
  */

#include "flot.hh"

Flot::Flot(float v) {
    this->val = v;
}

float get_flot() {
    return this->val;
}

void set_flot(float v) {
    this->val = v;
}
