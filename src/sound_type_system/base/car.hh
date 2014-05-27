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
  */


#ifndef CAR_HH
#define CAR_HH

#include <string>
#include "exp.hh"

class Car: public Exp {
    public:
        /** class constructor */
        Car() { this->type = "car"; } 
};

#endif
