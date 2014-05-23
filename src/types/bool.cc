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
  */

#include "bool.hh"
#include <string>

using namespace std;


/**
  * Returns the value of Bool object
  * @return val
  */

int Bool::get() {
    return this->val;
}


/**
  * Sets new value to Bool object 
  * @param v : new value  
  */

void Bool::set(bool v) {
    this->val = v;
}
