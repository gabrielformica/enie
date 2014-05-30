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
  * Mientras class definition 
  */

#ifndef MIENTRAS_HH
#define MIENTRAS_HH

#include <string>
#include "node.hh" 
#include "instruc.hh"
#include "decl.hh"
#include "exp.hh"

class Mientras: public Instruc {
    private:
        Exp *cond;
        InstList *instlist;

    public:
        typedef Instruc super;

        Mientras(Exp *cond, InstList *instlist) : super(NULL) {
            this->cond = cond;
            this->instlist = instlist;
            this->setType();
        }

        void setType() {
            this->type = this->cond->getType(); //setting type

            if (this->instlist->getType()->is("error")) {
                this->type = this->instlist->getType();
            }
        }
};

#endif
