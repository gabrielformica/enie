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
  * Class definitions for integer type
  *
  * THIS IS A USER CONSTRUCTOR TYPE
  */


#ifndef REGISTRO_HH
#define REGISTRO__HH

#include <string>
#include <list>
#include "type.hh"
#include "../../symtable/symtable.hh"
#include "../../symtable/symbol.hh"


class Registro: public ConstructorType {
    public:
        typedef ConstructorType super;

        /** Class constructor */

        Registro() : super() { }

        std::string typeString() { return "registro"; }

        bool is(std::string t) { return (t == "registro" || t == "constructor"); }
};

#endif
