/**
  * Copyright 2014
  *
  * @file instruct.hh
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for base instruction type
  */



#ifndef INSTRUC_HH
#define INSTRUC_HH

#include "node.hh"
#include "../interm_code/quad.hh"

class Instruc: public Node {
    protected:
        int line;
    public:
        typedef Node super;

        Instruc(Type *t) : super(t) { }

        int getLine() { return this->line; }
        void setLine(int line) { this->line = line; }

        virtual std::string toString() = 0;

        virtual Quad *genCode() = 0;
};

#endif
