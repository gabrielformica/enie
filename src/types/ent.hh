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
  * Class definitions for integer type
  */


#ifndef ENT_HH
#define ENT_HH

#include <string>
#include "exp.hh"

class Ent: public Exp {
    public:
        /** class constructor */
        Ent() { this->type = "ent"; } 
};

#endif
