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
  * Class definitions for expressions
  */


#ifndef EXP_HH
#define EXP_HH

#include <string>
#include "node.hh"
#include "../sound_type_system/base/type.hh"

class Exp: public Node {
    protected:
        char *op;  // +, -, !

    public:
        typedef Node super;

        /** Class constructor */
        Exp(Type *t) : super(t) { }

        std::string getTypeStr() { return this->type->typeString(); }

        virtual std::string toString() = 0;

        void setUnaryOperator(char *op) { this->op = op; }

        char *getUnaryOperator() { return this->op; }

        std::string opToString() {
            if (this->op == NULL) 
                return "";  

            return this->op;
        }

};

#endif
