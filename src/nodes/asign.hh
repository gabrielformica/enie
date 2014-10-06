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
#include "../interm_code/quad.hh"

class Asign: public Instruc {
    private:
        Exp *lhs;
        Exp *rhs;

    public:
        typedef Instruc super;

        Asign(Exp *l, Exp *r, Type *t) : lhs(l), rhs(r), super(t) { }

        Exp* getLeft() { return this->lhs; }
        Exp* getRight() { return this->rhs; }

        std::string toString() {
            std::string str = "Asignacion: \n";
            str = str + "lado izquierdo: " + this->lhs->toString() + "\n";
            str = str + "lado izquierdo: " + this->rhs->toString() + "\n";

            return str;
        }

        Quad *genCode() {
            //If it is a Symbol
            if (this->lhs->is("ExpVar")) {
                Quad *right = this->rhs->genCode();
                Symbol *s = ((ExpVar *) this->lhs)->getVar();
                Argument *result = new ArgumentVar(s, this->type);
                Quad *q = new Quad(":=", 
                                    right->getFinal()->getResult(),
                                    NULL,
                                    result);

                right->appendToFinal(q);
                return right;
            }
            //What if... x[i] = ?
            return NULL;
        }
};

#endif
