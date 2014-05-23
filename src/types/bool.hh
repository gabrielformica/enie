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
  * Class definitions for boolean type
  */


#ifndef BOOL_HH
#define BOOL_HH

#include <string>
#include "exp.hh"

class Bool: public Exp {
    private:
        bool val;
    public:
        explicit Bool(bool v) : val(v) { }
        int get();
        void set(bool v);

        /** Exp methods */
        std::string check() { return "bool"; };
        int offset() { return 1; };  //1 byte
};

#endif
