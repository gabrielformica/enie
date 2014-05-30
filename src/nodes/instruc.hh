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

class Instruc: public Node {
    public:
        typedef Node super;

        Instruc(Type *t) : super(t) { }
};

#endif
