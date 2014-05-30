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

        std::string toString() {
            std::string str = "";
            str = "Selecion:\n";
             
            str = str + "Condicion: " + this->cond->toString() + "\n";
            str = str + "Bloque de instrucciones: " + this->block->toString();

            if (this->osi != NULL) {
                str = str +  this->osi->toString() + "\n";
            }

            if (this->sino != NULL) {
                str = str + "Bloque Sino" + this->sino->toString() + "\n";
            }
            

            return str;
        }

};

#endif
