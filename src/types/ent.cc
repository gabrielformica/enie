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


#include "ent.hh"
#include <string>

using namespace std;


/**
  * Returns the value of Ent 
  * @return val
  */

int Ent::getValue() {
    return this->value;
}


/**
  * Sets new value to Ent
  * @param v : new value  
  */

void Ent::setValue(int v) {
    this->value = v;
}
