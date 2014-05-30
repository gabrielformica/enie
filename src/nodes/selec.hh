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
  * Class definitions for selection instruction type
  */


#ifndef SELEC_HH
#define SELEC_HH

#include <string>
#include <list>
#include "node.hh"
#include "exp.hh"
#include "instruc.hh"
#include "instlist.hh"
#include "osi.hh"

class Selec: public Instruc {
    private:
        Exp *cond;
        InstList *block;
        Osi *osi;
        InstList *sino;

    public:
        typedef Instruc super;

        Selec(Exp *cond, InstList *il, Osi *osi, InstList *sino) : super(NULL) {
            this->cond = cond;
            this->block = il;
            this->osi = osi;
            this->sino = sino;
            if (cond->getType()->is("error")) {
                this->type = cond->getType();
                return;
            }
            if (il == NULL) {
                this->type = new TypeError("Cuerpo de if es null");
                return;
            }

            this->type = il->getType();   //setting void or error
            if (il->getType()->is("error")) 
                return;

            if ((osi != NULL) && (osi->getType()->is("error"))) {
                this->type = osi->getType();
                return;
            }
        };

};

#endif
