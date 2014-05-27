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

class Signa {
    private: 
        ArgList *arglist;
        std::string return_type;

    public:
        Signa(ArgList *, std::string);
};

#endif
