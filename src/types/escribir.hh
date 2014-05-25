/**
  * Copyright 2014
  *
  * @file escribir.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for write instruction
  *
  */

#ifndef ESCRIBIR_HH
#define ESCRIBIR_HH

class Escribir {
    private:
        Exp *exp;
    public:
        explicit Escribir(Exp *e) { this->exp = e; }
};

#endif
