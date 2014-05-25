/**
  * Copyright 2014
  *
  * @file decl.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definition for declaration instruction type
  *
  */


#ifndef DECL_HH
#define DECL_HH

#include "exp.hh"
#include "instruc.hh"
#include "../symtable.hh"

class Decl : public Instruc {
    private:
        Symbol *sym;
        Exp *exp;

    public:
        typedef Instruc super;

        Decl(Symbol *s, Exp *e);

        Symbol* getSymbol();
        Exp* getExpression();
        void setSymbol(Symbol *s);
        void setExpression(Exp *e);
        bool check();
};

#endif
