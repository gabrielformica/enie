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
  * Class definitions for floating point type
  */


#include "flot.hh"
#include <string>

using namespace std;


/**
  * Returns the value of Flot 
  * @return val
  */

float Flot::getValue() {
    return this->value;
}


/**
  * Sets new value to Ent
  * @param v : new value  
  */

void Flot::setValue(float v) {
    this->value = v;
}
