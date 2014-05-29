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
#include "../symtable/symtable.hh"
#include "../symtable/symbol.hh"

class Decl : public Node {
    private:
        Symbol *lhs;
        Exp *rhs;

    public:
        typedef Node super;

        Decl(Symbol *lhs, Exp *rhs, Type *t) : super(t) {
            this->lhs = lhs;
            this->rhs = rhs;
        }

        Symbol* getSymbol();
        Exp* getExpression();
};

#endif
