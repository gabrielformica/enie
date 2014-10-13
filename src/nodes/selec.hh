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
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"

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

        Quad *genCode() {
            // Labels for jumping code
            std::string true_label = get_next_label();
            std::string false_label = get_next_label();
            ArgumentConst *true_arg = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);

            // Generation of jumping code and label for true
            Quad *cond_quad = this->cond->genJumpingCode(true_label, false_label);


            Quad *true_quad = new Quad("label", NULL, NULL, true_arg);
            cond_quad->appendToFinal(true_quad);
            cond_quad->appendToFinal(this->block->genCode());

            // si () {}
            if (this->osi == NULL and this->sino == NULL ) {
                Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
                cond_quad->appendToFinal(false_quad);

            // si () {} osi () {} osi {} ...
            }
            else if (this->osi != NULL and this->sino == NULL) {
                // Exit label after SI block
                std::string exit_label = get_next_label();
                ArgumentConst *exit_arg = new ArgumentConst(exit_label, NULL);
                Quad *goto_exit = new Quad("goto", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(goto_exit);

                // If condition is false
                Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
                cond_quad->appendToFinal(false_quad);

                // OSI instructions quads
                Quad *osi_quad = this->osi->genCode(exit_arg);
                cond_quad->appendToFinal(osi_quad);

                // Exit label for complete block
                Quad *exit_quad = new Quad("label", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(exit_quad);
            }
            // si () {} sino {}
            else if (this->osi == NULL and this->sino != NULL) {
                // Exit label after SI block
                std::string exit_label = get_next_label();
                ArgumentConst *exit_arg = new ArgumentConst(exit_label, NULL);
                Quad *goto_exit = new Quad("goto", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(goto_exit);

                // If condition is false
                Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
                cond_quad->appendToFinal(false_quad);

                Quad *sino_quad = this->sino->genCode();
                cond_quad->appendToFinal(sino_quad);

                // Exit label for complete block
                Quad *exit_quad = new Quad("label", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(exit_quad);
            }
            // si () {} osi () {} osi {} ... sino {}
            else {
                // Exit label after SI block
                std::string exit_label = get_next_label();
                ArgumentConst *exit_arg = new ArgumentConst(exit_label, NULL);
                Quad *goto_exit = new Quad("goto", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(goto_exit);

                // If condition is false
                Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
                cond_quad->appendToFinal(false_quad);

                // OSI instructions quads
                Quad *osi_quad = this->osi->genCode(exit_arg);
                cond_quad->appendToFinal(osi_quad);

                // SINO instructions quads
                Quad *sino_quad = this->sino->genCode();
                cond_quad->appendToFinal(sino_quad);

                // Exit label
                Quad *exit_quad = new Quad("label", NULL, NULL, exit_arg);
                cond_quad->appendToFinal(exit_quad);
            }

            return cond_quad;

        }

};

#endif
