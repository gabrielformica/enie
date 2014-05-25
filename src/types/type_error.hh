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
        int line;
        int column;
        Exp *exp;

    public:
        typedef Exp super;

        explicit TypeError(int l, int c, Exp *e) : 
                 line(l), column(c), exp(e), super("error") {}

};

#endif
