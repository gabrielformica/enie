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

class Expbin: public Exp {
    private:
        Exp *left;
        Exp *right;
        std::string type;

    public:
        explicit Expbin(Exp *l, Exp *r, std::string t) : 
                 left(l), right(r), type(t) { }

        /** Exp methods */
        std::string getType() { return type; };

};

#endif
