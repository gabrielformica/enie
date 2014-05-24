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
        typedef Exp super;

        explicit Arreglo(std::string elem_t, int f, int l) :  
                 super("arr("+elem_t+")"), 
                 elem_type(elem_t),  
                 first_index(f),
                 last_index(l)
                 { }

};

#endif
