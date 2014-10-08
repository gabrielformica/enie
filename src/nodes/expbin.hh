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
#include "../interm_code/quad.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/argument.hh"
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

        bool is(std::string str) { return "ExpBin"; }

        std::string toString() {
            std::string signo = "";
            if (this->op != "")
                signo = "Signo: " + this->op;

            std::string str = "Expresion Binaria: " + signo + "\n";
            str = str + "Operando izquierdo: " + this->left->toString() + "\n";
            str = str + "Operador: " + this->ope + "\n";
            str = str + "Operando derecho: " + this->right->toString() + "\n";
            return str;
        }

        Quad *genCode() {
            Quad *q1 = this->left->genCode();
            Quad *q2 = this->right->genCode();
            Symbol *s = get_next_temp();
            Argument *r = new ArgumentVar(s, this->type);

            Quad *q3 = new Quad(this->ope,
                                q1->getFinal()->getResult(),
                                q2->getFinal()->getResult(),
                                r);

            q1->appendToFinal(q2);

            gen_un_op(q3, this->op);

            q2->appendToFinal(q3);

            return q1;
        }


        Quad *genJumpingCode(std::string true_label, std::string false_label) {
            Quad *q1 = this->left->genCode();
            Quad *q2 = this->right->genCode();
            ArgumentConst *true_arg  = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);

            Quad *q_false = new Quad("goto", false_arg, NULL, false_arg);

            // ++ q_false
        }
};

#endif
