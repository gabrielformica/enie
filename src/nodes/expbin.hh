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
  * Class definitions for binary expressions
  */


#ifndef EXPBIN_HH
#define EXPBIN_HH

#include <string>
#include "node.hh"
#include "exp.hh"
#include "../sound_type_system/base/type.hh"

class ExpBin: public Exp {
    private:
        Exp *left;
        Exp *right;

    public:
        typedef Exp super;

        /** class constructor */
        ExpBin(Exp *left, Exp *right, Type *type) : super(type) { 
            this->left = left;
            this->right = right;
        } 

};

#endif
