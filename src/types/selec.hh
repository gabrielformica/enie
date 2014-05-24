/**
  * Copyright 2014
  *
  * @file selec.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for selection instruction type
  *
  */


#ifndef SELEC_HH
#define SELEC_HH

#include <list>
#include "exp.hh"
#include "instruc.hh"
#include "instbl.hh"
#include "oselec.hh"
#include "oseleclist.hh"

class Selec : public Instruc {
    private:
        Exp *exp;
        Instbl *block;
        Oseleclist *oselecList;

    public:
        typedef Instruc super;

        explicit Selec(Exp *e, Instbl *bl) : exp(e), block(bl) { }

        Exp* getExpression();
        Oseleclist* getList();
        Instbl* getBlock();
        bool check();
};

#endif
