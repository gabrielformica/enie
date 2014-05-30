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

        void setType() {
            this->type = this->opt->getType(); //setting type
            
            if (this->bloque->getType()->is("error"))
                this->type = this->bloque->getType();

        }
};

#endif
