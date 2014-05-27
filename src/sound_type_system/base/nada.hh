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
  * Class definitions for nada type
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef NADA_HH
#define NADA_HH 

#include "type.hh"

class Nada: public Type {
    public:
        typedef Type super;

        /** class constructor */
        Nada() : super(0) { } 
};

#endif