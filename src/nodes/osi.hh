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
  * Class definitions for osi instruction type
  */


#ifndef OSI_HH
#define OSI_HH

#include <string>
#include "exp.hh"
#include "node.hh"
#include "instruc.hh"
#include "instlist.hh"

class Osi: public Instruc {
    private:
        Exp *cond;
        InstList *block;
        Osi *osi;

    public:
        typedef Instruc super;

        Osi(Exp *cond, InstList *il, Osi *osi) : super(NULL) {
            this->cond = cond;
            this->block = il;
            this->osi = osi;


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
        }

};

#endif