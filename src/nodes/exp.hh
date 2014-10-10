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
#include "../interm_code/quad.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../sound_type_system/base/type.hh"

class Exp: public Node {
    protected:
        std::string op;  // +, -, !

    public:
        typedef Node super;

        /** Class constructor */
        Exp(Type *t) : super(t) { }

        std::string getTypeStr() { return this->type->typeString(); }

        virtual std::string toString() = 0;

        virtual bool is(std::string) = 0;

        void setUnaryOperator(std::string op) { this->op = op; }

        std::string getUnaryOperator() { return this->op; }

        virtual Quad *genCode() = 0;
        virtual Quad *genJumpingCode(std::string a, std::string b) = 0;
};

#endif
