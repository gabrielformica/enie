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

class Exp : public Node {
    protected:
        std::string elem;

    public:
        typedef Node super;

        /** Class constructor */
        Exp(std::string elem, Type *t) : super(t) {
            this->elem = elem;
        }

        Exp(Type *t) : super(t) {
            this->elem = "";
        }

        std::string getTypeStr() { return this->type->typeString(); }

        std::string getElem() { return this->elem; }

};

#endif
