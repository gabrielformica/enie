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
#include "../sound_type_system/type_system_utils.hh"

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
            Argument *false_arg = new ArgumentConst(false_label, NULL);
            Argument *true_arg = new ArgumentConst(true_label, NULL);

            if (this->op == "!") {
                Argument *temp = true_arg;
                true_arg = false_arg;
                false_arg = temp;
            }
            
            if (this->ope == "&") {
                 std::string new_label = get_next_label();
                 Argument *new_label_arg = new ArgumentConst(new_label, NULL);

                 Quad *l = this->left->genJumpingCode(new_label, false_label);
                 Quad *r = this->right->genJumpingCode(true_label, false_label);

                 Quad *label_quad = new Quad("label", NULL, NULL, new_label_arg);
                 l->appendToFinal(label_quad);
                 l->appendToFinal(r);

                 return l;
            }
            else if (this->ope == "|") {
                 std::string new_label = get_next_label();
                 Argument *new_label_arg = new ArgumentConst(new_label, NULL);

                 Quad *l = this->left->genJumpingCode(true_label, new_label);
                 Quad *r = this->right->genJumpingCode(true_label, false_label);

                 Quad *label_quad = new Quad("label", NULL, NULL, new_label_arg);
                 l->appendToFinal(label_quad);
                 l->appendToFinal(r);

                 return l;
            }
            else if (this->ope == "<" || this->ope == "<=" || 
                     this->ope == ">" || this->ope == ">=" ||
                     this->ope == "==" || this->ope == "!=") {


                Quad *l = this->left->genCode();
                Quad *r = this->right->genCode();

                Argument *arg1 = l->getFinal()->getResult();
                Argument *arg2 = r->getFinal()->getResult();
                Quad *jump = NULL;
                if (this->ope == "<")
                    jump = new Quad("blt", arg1, arg2, true_arg);
                else if (this->ope == "<=")
                    jump = new Quad("ble", arg1, arg2, true_arg);
                else if (this->ope == ">")
                    jump = new Quad("bgt", arg1, arg2, true_arg);
                else if (this->ope == ">=")
                    jump = new Quad("bge", arg1, arg2, true_arg);
                else if (this->ope == "==")
                    jump = new Quad("beq", arg1, arg2, true_arg);
                else if (this->ope == "!=")
                    jump = new Quad("bne", arg1, arg2, true_arg);

                l->appendToFinal(r);
                
                l->appendToFinal(jump);

                Quad *goto_false = new Quad("goto", NULL, NULL, false_arg);
                l->appendToFinal(goto_false);

                return l;
            }
            return NULL;
        }
};

#endif
