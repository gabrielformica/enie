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
  * Void class definition
  */


#ifndef VOID_HH
#define VOID_HH

#include <string>
#include "type.hh"

class Void: public Type {
    public:
        typedef Type super;

        /** Class constructor */    
        Void() : super(0) { }

        std::string typeString() { return "void"; }
        bool is(std::string t) { return t == "void"; }
        void setBytes() { this->bytes = 0; }
};

#endif
