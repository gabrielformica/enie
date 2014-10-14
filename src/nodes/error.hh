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
  * Class definition for sytax error object
  */


#ifndef ERROR_HH
#define ERROR_HH

#include <string>
#include "node.hh"
#include "../sound_type_system/base/type.hh"


class Error: public Node {
    public:
        typedef Node super;

        /** Class constructor */
        Error(Type *t) : super(t) { }

        std::string getTypeStr() { return this->type->typeString(); }

        std::string toString() { return ""; } // maybe change this later

        Quad *genCode() { return NULL; }
};

#endif
