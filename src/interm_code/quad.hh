/**
  * Copyright 2014
  *
  * @file
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Quad class definition
  */

#ifndef QUAD_HH
#define QUAD_HH

#include <string>
#include "quad_utils.hh"
#include "../symtable/symbol.hh"
#include "../sound_type_system/base/type.hh"

class Quad {
    virtual std::string emit() = 0;
};

#endif
