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
};

#endif
