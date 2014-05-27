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
    public:
        typedef Node super;

        /** Class constructor */
        Exp(Type *t) : super(t) { }
        std::string getTypeStr() { return type->typeString(); }

};

#endif
