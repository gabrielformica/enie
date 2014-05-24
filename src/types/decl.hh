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

        explicit Decl(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* get_symbol();
        Exp* get_expression();
        void set_symbol(Symbol *s);
        void set_expression(Exp *e);
        bool check();
};

#endif
