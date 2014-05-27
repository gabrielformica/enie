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
  * Function class definition
  */


#ifndef FUNCTION_HH
#define FUNCTION_HH

#include <string>
#include "header.hh"
#include "instbl.hh"

class Function {
    private:
        Header *header;
        Instbl *instbl;

    public:
        Function(Header *, Instbl *);

};

#endif
