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
#include "exp.hh"

class ExpBin: public Exp {
    private:
        Exp *left;
        Exp *right;

    public:
        /** class constructor */
        ExpBin(Exp *l, Exp *r) { 
            this->left = l;
            this->right = l;
            this->type = l->getType(); 
        } 

};

#endif
