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
  */


#ifndef NADA_HH
#define NADA_HH 

#include <string>
#include "exp.hh"

class Nada: public Exp {
    public:
        /** class constructor */
        Nada() { this->type = "nada"; } 
};

#endif
