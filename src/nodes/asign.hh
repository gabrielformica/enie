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

class Asign: public Node {
    private:
        Exp *lhs;
        Exp *rhs;

    public:
        typedef Node super;

        Asign(Exp *l, Exp *r, Type *t) : lhs(l), rhs(r), super(t) { }

        Exp* getLeft() { return this->lhs; }
        Exp* getRight() { return this->rhs; }
};

#endif
