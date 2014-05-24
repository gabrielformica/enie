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
  * Class definitions for floating point type
  */


#ifndef FLOT_HH
#define FLOT_HH

#include <string>
#include "exp.hh"

class Flot: public Exp {
    public:
        typedef Exp super;

        explicit Flot() : super("flot") { }
};

#endif
