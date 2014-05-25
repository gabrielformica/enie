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

#include "instruc.hh"
#include "../symtable.hh"
#include "optlist.hh"

class Multselec: public Instruc {
    private:
        Symbol *sym;
        Optlist *optl;

    public:
        Multselec(Symbol *s, Optlist *ol);

        void setSymbol(Symbol *s);
        Symbol* getSymbol();
        bool check();
};

#endif
