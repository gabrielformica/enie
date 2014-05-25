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
  * Class definitions for type error
  */


#ifndef TYPE_ERROR_HH
#define TYPE_ERROR_HH

#include <string>
#include "exp.hh"

class TypeError: public Exp {
    private:
        Exp *exp;
        int line;
        int column;

    public:
        /** class constructor */
        TypeError(Exp *e, int l, int c) { 
            this->exp = e;
            this->line = l;
            this->column = c;
            this->type = "error";
        } 
};

#endif
