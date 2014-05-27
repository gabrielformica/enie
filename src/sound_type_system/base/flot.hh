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
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef FLOT_HH
#define FLOT_HH

#include "type.hh"

class Flot: public Type {
    public:
        typedef Type super;
        
        /** class constructor */
        Flot() : super(8) { } 
};

#endif