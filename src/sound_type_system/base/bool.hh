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
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef BOOL_HH
#define BOOL_HH

#include <string>
#include "type.hh"

class Bool: public Type {
    public:
        typedef Type super;

        /** class constructor */
        Bool() : super(1) { }

        std::string typeString() { return "bool"; }
        bool is(std::string t) { return t == "bool"; }
        void setBytes() { this->bytes = 1; }
};

#endif
