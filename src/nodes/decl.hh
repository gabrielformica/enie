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

class Decl : public Instruc {
    private:
        Symbol *lhs;
        Exp *rhs;

    public:
        typedef Instruc super;

        Decl(Symbol *lhs, Exp *rhs, Type *t) : super(t) {
            this->lhs = lhs;
            this->rhs = rhs;
        }

        Symbol* getLeft() { return this->lhs; }
        Exp* getRight() { return this->rhs; }

        std::string Instruc::toString() {
            std::string str = ""; 
            str = "Declaracion: \n";  
            str = str + this->lhs->getId() + "\n";
            if (! (this->rhs == NULL)) {
                str = str + "Variable : " + this->rhs->toString();
            }

            return str;
        }
};

#endif
