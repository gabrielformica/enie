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
  * Type System function definitions
  */


#ifndef TYPE_SYSTEM_HH
#define TYPE_SYSTEM_HH

#include <string>
#include "exp.hh"
#include "expbin.hh"
#include "ent.hh"
#include "flot.hh"

bool check_expbin(Exp *, Exp *, std::string);

bool is_arithmetic(std::string);

bool is_boolean(std::string);

bool is_relational(std::string);

#endif
