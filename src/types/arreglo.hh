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
  * Class definitions for array type
  */


#ifndef ARRAY_HH
#define ARRAY_HH 

#include <string>
#include "exp.hh"

class Arreglo: public Exp {
    private:
        std::string elem_type;
        int first_index;
        int last_index;
 
    public: 
        /** class constructor */
        Arreglo(int f, int l, std::string elem_t) { 
            this->elem_type = elem_t;
            this->first_index = f;
            this->last_index = l;
            this->type = "array(" + elem_t + ")";
        } 

};

#endif
