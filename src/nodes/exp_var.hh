/**
  * Copyright 2014
  *
  * @file
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for simple expressions that are a variable
  */

#ifndef EXP_VAR_HH
#define EXP_VAR_HH

#include "../symtable/symbol.hh"

class ExpVar: public ExpSimple {
    protected:
        Symbol *var;
    public:
        typedef ExpSimple super;

        /** Class constructor */
        ExpVar(Type *t) : super(t) { this->var = NULL; };

        ExpVar(Symbol *s, Type *t) : super(s->getId(), t) { 
            this->var = s;
        } 

        bool is(std::string str) { return "ExpVar"; }
};

#endif
