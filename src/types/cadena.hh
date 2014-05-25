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
  * Class definitions for cadena type
  */


#ifndef CADENA_HH
#define CADENA_HH

#include <string>
#include "exp.hh"

class Cadena: public Exp {
    public:
        /** class constructor */
        Cadena() { this->type = "cadena"; } 
};

#endif
