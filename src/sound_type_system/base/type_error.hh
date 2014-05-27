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

#include "type.hh"
#include "nodes/exp.hh"

class TypeError: public Type {
    private:
        Exp *exp;
        int line;
        int column;

    public:
        typedef super Type;

        /** class constructor */
        TypeError(Exp *e, int l, int c) : super(0) { 
            this->exp = e;
            this->line = l;
            this->column = c;
        } 
};

#endif
