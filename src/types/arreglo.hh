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
        std::string type;
        size_t size;  //size of array = size of elements * number of elements
        void *value;
 
    public: 
        explicit Arreglo(size_t s, void *v = 0) : size(s), value(v) { }

        void setValue(void *v);

        /** Exp methods */
        std::string getType() { return "arreglo"; }
        int offset() { return size; }  //size of elements * number of elements

};

#endif
