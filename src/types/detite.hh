/**
  * Copyright 2014
  *
  * @file detite.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for determined iteration instruction type
  *
  */


#ifndef DETITE_HH
#define DETITE_HH

#include "exp.hh"
#include "instbl.hh"
#include "decl.hh"
#include "instruc.hh"

class Detite : public Instruc {
    private:
        Exp *exp;
        Instbl *block;
        Decl *declar;

    public:
        typedef Instruc super;

        explicit Detite(Exp *e, Instbl *bl, Decl *de) : exp(e), block(bl),
                        declar(de) { }

        Exp* getExpression();
        Instbl* getBlock();
        Decl* getDecl();
        bool check();
};

#endif
