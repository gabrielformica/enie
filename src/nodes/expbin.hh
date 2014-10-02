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
  * Class definitions for binary expressions
  */


#ifndef EXPBIN_HH
#define EXPBIN_HH

#include <string>
#include "node.hh"
#include "exp.hh"
#include "../sound_type_system/base/type.hh"

class ExpBin: public Exp {
    private:
        Exp *left;
        Exp *right;
        std::string ope;

    public:
        typedef Exp super;

        /** class constructor */
        ExpBin(Exp *left, Exp *right, std::string ope, Type *type) :
            super(type) {

            this->left = left;
            this->right = right;
            this->ope = ope;
        }


        Exp *getLeft() { return this->left; }
        Exp *getRight() { return this->right; }
        std::string getOperator() { return this->ope; }

        std::string toString() {
            std::string signo = "";
            if (this->op != NULL)
                signo = "Signo: " + this->opToString();

            std::string str = "Expresion Binaria: " + signo + "\n";
            str = str + "Operando izquierdo: " + this->left->toString() + "\n";
            str = str + "Operador: " + this->ope + "\n";
            str = str + "Operando derecho: " + this->right->toString() + "\n";
            return str;
        }
};

#endif
