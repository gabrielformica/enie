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
  * Signa class definition
  */


#ifndef SIGNA_HH
#define SIGNA_HH

#include <string>
#include "arglist.hh"

class Signa: public Node {
    private: 
        ArgList *arglist;
        std::string return_type;

    public:
        typedef Node super;

        Signa(ArgList *, std::string ret, Type *t) : super(t);
};

#endif
