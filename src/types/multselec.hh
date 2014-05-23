/**
  * Copyright 2014
  *
  * @file multselec.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for case instruction type
  *
  */


#ifndef MULTSELEC_HH
#define MULTSELEC_HH

#include "exp.hh"
#include "instruc.hh"
#include "../symtable.hh"

class Multselec: public Instruc {
    private:
        Symbol *sym;
        Exp *exp;

    public:
        explicit Multselec(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* getSymbol();
        Exp* getExpression();
        void setSymbol(Symbol *s);
        void setExpression(Exp *e);
        bool check();
};

#endif
