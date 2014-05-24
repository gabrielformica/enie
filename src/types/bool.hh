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
  * Class definitions for boolean type
  */


#ifndef BOOL_HH
#define BOOL_HH

#include <string>
#include "exp.hh"

class Bool: public Exp {
    public:
        typedef Exp super;

        explicit Bool() : super("bool") { }
};

#endif
