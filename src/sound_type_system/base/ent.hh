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
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef ENT_HH
#define ENT_HH

#include <string>
#include "type.hh"

class Ent: public Type {
    public:
        typedef Type super;

        /** Class constructor */
        Ent() : super(4) { } 

        std::string typeString() { return "ent"; }
};

#endif
