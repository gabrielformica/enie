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
#include "base/type.hh"
#include "base/ent.hh"
#include "base/flot.hh"
#include "../nodes/node.hh"
#include "../nodes/exp.hh"
#include "../nodes/expbin.hh"

Exp *get_expbin(Exp *, Exp *, std::string);

bool check_expbin(Exp *, Exp *, std::string);

bool is_arithmetic_ent(std::string);

bool is_arithmetic_flot(std::string);

bool is_boolean(std::string);

bool is_relational(std::string);

#endif
