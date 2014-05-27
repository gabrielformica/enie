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
#include "../symtable/symtable.hh"

class Asign: public Instruc {
    private:
        Symbol *sym;
        Exp *exp;
    public:
        Asign(Symbol *s, Exp *e);

        Symbol* get_symbol();
        Exp* getExpression();
        void setSymbol(Symbol *s);
        void setExpression(Exp *e);
        bool check();
};

#endif
