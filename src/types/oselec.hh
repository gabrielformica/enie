/**
  * Copyright 2014
  *
  * @file oselec.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for selection's else if instruction type
  *
  */


#ifndef OSELEC_HH
#define OSELEC_HH

#include "exp.hh"
#include "instbl.hh"

class Oselec : public Instruc {
    private:
        Exp *exp;
        Instbl *block;
    public:
        typedef Instruc super;

        explicit Oselec(Exp *e, Instbl *bl) : exp(e), block(bl) { }

        Exp* getExpression();
        Instbl* getBlock();
        bool check();
};

#endif
