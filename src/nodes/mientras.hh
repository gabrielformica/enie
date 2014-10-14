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
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"

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

        std::string toString() {
            std::string str = "";
            str = "Iteracion indeterminada:\n";
            str = str + "Condicion: " + this->cond->toString();
            str = str + "Bloque de instrucciones: " + this->instlist->toString();

            return str;
        }

        Quad *genCode() {
            // Labels for jumping code
            std::string true_label = get_next_label();
            std::string false_label = get_next_label();
            std::string begin_label = get_next_label();

            Quad *comment = new Quad(this->line, "Mientras");
            Quad *last_comment = new Quad(this->line, "Cierre-Mientras");

            ArgumentConst *true_arg = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);
            ArgumentConst *begin_arg = new ArgumentConst(begin_label, NULL);

            // Begin label quad is appended
            Quad *code = new Quad("label", NULL, NULL, begin_arg);
            comment->appendToFinal(code);   //Put the comment first
            code->appendToFinal(this->cond->genJumpingCode(true_label, false_label));

            // True quad is appended
            Quad *true_quad = new Quad("label", NULL, NULL, true_arg);
            code->appendToFinal(true_quad);

            code->appendToFinal(this->instlist->genCode());

            // Go to begin
            Quad *goto_begin = new Quad("goto", NULL, NULL, begin_arg);
            code->appendToFinal(goto_begin);

            // False quad is appended
            Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
            code->appendToFinal(false_quad);

            comment->appendToFinal(last_comment);
            return comment;
        }

};

#endif
