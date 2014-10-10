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


#ifndef CASO_HH
#define CASO_HH

#include <vector>
#include <string>
#include "node.hh"
#include "instruc.hh"
#include "instlist.hh"
#include "lambda_opt.hh"

class Caso: public Instruc {
    private:
        ExpSimple *var;
        std::vector<LambdaOpt *> *optlist;
        LambdaOpt *otherwise;

    public:
        typedef Instruc super;

        Caso(ExpSimple *var, std::vector<LambdaOpt *> *optl, LambdaOpt *ow) :
            super(NULL) {
            this->var = var;
            this->optlist = optl;
            this->otherwise = ow;
            this->setType();
        }

        void setType() {
            this->type = this->var->getType(); //setting type

            int i;
            for (i = 0; i < this->optlist->size(); i++) {
                if ((*this->optlist)[i]->getType()->is("error"))
                    this->type = (*this->optlist)[i]->getType();
            }

            if (this->otherwise->getType()->is("error"))
                this->type = this->otherwise->getType();
        }

        std::string toString() {
            std::string str = "";
            str = "Caso:\n";
            str = str + "Variable: " + this->var->getElem() + "\n";
            str = str + "Conjunto de opciones: \n";
            for (int i = 0; i < this->optlist->size(); i++) {
                    str = str + (*this->optlist)[i]->toString() + "\n";
            }

            str = str + "Caso por defecto: (?) " + this->otherwise->toString();

            return str;
        }

        Quad *genCode() { return NULL; }
};

#endif
