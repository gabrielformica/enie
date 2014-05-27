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

#include "type.hh"

class Bool: public Type {
    public:
        typedef Type super;

        /** class constructor */
        Bool() : super(1) { }
};

#endif
