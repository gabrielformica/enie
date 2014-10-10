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
#include "../interm_code/quad.hh"

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

        std::string toString() {
                std::string str = "";
                str = "Bloque Osi:\n";

                str = str + "Condicion: " + this->cond->toString() + "\n";
                str = str + "Bloque de instrucciones: " + this->block->toString();

                if (this->osi != NULL) {
                    str = str + "Bloque Osi" + this->osi->toString() + "\n";
                }

                return str;
        }

        Quad *genCode(Argument *exit_arg) {
            std::string true_label = get_next_label();
            std::string false_label = get_next_label();
            ArgumentConst *true_arg = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);

            // Generation of jumping code and label for true
            Quad *cond_quad = this->cond->genJumpingCode(true_label, false_label);
            Quad *true_quad = new Quad("label", NULL, NULL, true_arg);
            cond_quad->appendToFinal(true_quad);

            // Append instructions block quads
            // Quad *block_quad = this->block->genCode();
            // cond_quad->appendToFinal(block_quad);

            // Append goto exit
            Quad *goto_exit = new Quad("goto", NULL, NULL, exit_arg);
            cond_quad->appendToFinal(goto_exit);

            Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
            cond_quad->appendToFinal(false_quad);

            if (this->osi != NULL) {
                Quad *osi_quad = this->osi->genCode(exit_arg);
                cond_quad->appendToFinal(osi_quad);
            }

            return cond_quad;
        }

};

#endif
