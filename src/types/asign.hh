/**
  * Copyright 2014
  *
  * @file asign.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for asignment instruction
  *
  */


#ifndef ASIGN_HH
#define ASIGN_HH

#include "exp.hh"
#include "instruc.hh"
#include "../symtable.hh"

class Asign: public Instruc {
    private:
        Symbol *sym;
        Exp *exp;
    public:
        explicit Asign(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* get_symbol();
        Exp* get_expression();
        void set_symbol(Symbol *s);
        void set_expression(Exp *e);
        bool check();
};

#endif
