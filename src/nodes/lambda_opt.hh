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
  * Caso class definition
  */


#ifndef LAMBDA_OPT_HH
#define LAMBDA_OPT_HH

#include "node.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"


class LambdaOpt: public Node {
    private:
        Exp *opt;
        InstList *bloque;

    public:
        typedef Node super;

        LambdaOpt(Exp *opt, InstList *bloque) : super(NULL) {
            this->opt = opt;
            this->bloque = bloque;
            this->setType();
        }

        Exp *getOpt() {
            return this->opt;
        }

        void setType() {
            this->type = this->opt->getType(); //setting type

            if (this->bloque->getType()->is("error"))
                this->type = this->bloque->getType();

        }

        std::string toString() {
            std::string str = "";
            str = "Opcion:  " + this->opt->toString() + "\n";
            str = str + "Bloque opt: " + this->bloque->toString();

            return str;
        }

        Quad *genCode(Argument *exit_arg) {
            Quad *opt_quad = new Quad(0,"");

            // Code for instructions of option
            Quad *inst_quad = this->bloque->genCode();
            opt_quad->appendToFinal(inst_quad);

            // Goto exit
            Quad *goto_exit = new Quad("goto", NULL, NULL, exit_arg);
            opt_quad->appendToFinal(goto_exit);

            return opt_quad;
        }

        Quad *genCode() { return NULL; }
};

#endif
