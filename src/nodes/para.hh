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
  * Para class definition
  */


#ifndef PARA_HH
#define PARA_HH

#include <string>
#include "node.hh"
#include "instruc.hh"
#include "decl.hh"
#include "exp.hh"
#include "instlist.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"


class Para: public Instruc {
    private:
        Decl *decl;
        Exp* left;
        Exp* right;
        InstList *block;

    public:
        typedef Instruc super;

        Para(Decl *d, Exp *l, Exp *r, InstList *b) : super(NULL) {
            this->decl = d;
            this->left = l;
            this->right = r;
            this->block = b;
            this->setType();
        }

        void setType() {
            if (this->decl == NULL) {
                this->type = new TypeError("Declaracion nula");
                return;
            }
            else if (this->decl->getType()->is("error")) {
                this->type = this->decl->getType();
                return;
            }

            this->type = this->decl->getType(); //setting void type

            if (this->left->getType()->is("error")) {
                this->type = this->left->getType();
                return;
            }

            if (this->right->getType()->is("error")) {
                this->type = this->right->getType();
                return;
            }

            if (this->block->getType()->is("error")) {
                this->type = this->block->getType();
                return;
            }

        }

        std::string toString() {
            std::string str = "";

            str = "Iteracion determinada:\n";
            str = str + "Inicio: " + this->decl->toString() + "\n";
            str = str + "Condicion: " + this->left->toString() + "\n";
            str = str + "Cambio: " + this->right->toString() + "\n";
            str = str + "Bloque de instrucciones: " + this->block->toString();

            return str;
        }

        Quad *genCode() {
            std::string true_label = get_next_label();
            std::string false_label = get_next_label();
            std::string begin_label = get_next_label();

            ArgumentConst *true_arg = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);
            ArgumentConst *begin_arg = new ArgumentConst(begin_label, NULL);

            Quad *code = new QuadComment(0);
            code->appendToFinal(this->decl->genCode());

            // Begin label quad is appended
            code->appendToFinal(new Quad("label", NULL, NULL, begin_arg));

            code->appendToFinal(this->left->genJumpingCode(true_label, false_label));

            // True quad is appended
            Quad *true_quad = new Quad("label", NULL, NULL, true_arg);
            code->appendToFinal(true_quad);

            // Generate code for block of instructions
            code->appendToFinal(this->block->genCode());

            Quad *change = this->right->genCode();
            code->appendToFinal(change);

            Symbol *variable = this->decl->getLeft();
            Argument *var_arg = new ArgumentVar(variable, variable->getType());
            Quad *inc = new Quad(":=", change->getFinal()->getResult(),
                                NULL,
                                var_arg);
            code->appendToFinal(inc);

            // Go to begin
            Quad *goto_begin = new Quad("goto", NULL, NULL, begin_arg);
            code->appendToFinal(goto_begin);

            // False quad is appended
            Quad *false_quad = new Quad("label", NULL, NULL, false_arg);
            code->appendToFinal(false_quad);

            return code;
        }

};

#endif
