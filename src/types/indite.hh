/**
  * Copyright 2014
  *
  * @file indite.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for intermined iteration instruction type
  *
  */


#ifndef INEDITE_HH
#define INEDITE_HH

#include "exp.hh"
#include "instbl.hh"
#include "instruc.hh"

class Inedite : public Instruc {
    private:
        Exp *exp;
        Instbl *block;

    public:
        typedef Instruc super;

        explicit Inedite(Exp *e, Instbl *bl) : exp(e), block(bl) { }

        Exp* getExpression();
        Instbl* getBlock();
        bool check();
};

#endif
