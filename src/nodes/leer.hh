/**
  * Copyright 2014
  *
  * @file leer.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for read instruction
  *
  */

#ifndef LEER_HH
#define LEER_HH

#include "exp.hh"

class Leer {
    private:
        Exp *exp;
    public:
        explicit Leer(Exp *e) { this->exp = exp; }

        Exp* getExpression() { return this->exp; }
};

#endif
