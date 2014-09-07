/**
  * Copyright 2014
  *
  * @file asign.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for asignment instruction
  *
  */


#ifndef FUNCAPP_HH
#define FUNCAPP_HH

#include "exp.hh"
#include "instruc.hh"
#include "../symtable/symtable.hh"

class FuncApp: public Instruc {
    public:
        typedef Instruc super;

        FuncApp(Type *t) : super(t) { }


        std::string toString() {
            std::string str = "Llamada a funcion: \n";

            return str;
        }

};

#endif
