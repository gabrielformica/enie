/**
  * Copyright 2014
  *
  * @file retorno.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for return instruction
  *
  */

#ifndef RETORNO_HH
#define RETORNO_HH

class Retorno {
    private:
        Exp *exp;
    public:

        Retorno(Exp *e) : exp(e) { }

        Exp* getExpression() { return this->exp; }
};

#endif

