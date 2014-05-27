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
  * Function class implementation 
  */


#include <string>
#include "header.hh"
#include "instbl.hh"
#include "function.hh"


Function::Function(Header *header, Instbl *instbl) {
    this->header = header;
    this->instbl = instbl;
}
