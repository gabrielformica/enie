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
#include "instruc.hh"
#include "../symtable.hh"

class Inedite : public Instruc {
    private:
        Symbol *sym;
        Exp *exp;

    public:
        typedef Instruc super;

        explicit Inedite(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* get_symbol();
        Exp* get_expression();
        void set_symbol(Symbol *s);
        void set_expression(Exp *e);
        bool check();
};

#endif
