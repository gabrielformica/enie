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
  * Class definitions for car type 
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef CAR_HH
#define CAR_HH

#include "type.hh"

class Car: public Type {
    public:
        typedef Type super;

        /** class constructor */
        Car() : super(1) { } 
};

#endif
