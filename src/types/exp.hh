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

class Exp {
    protected:
        std::string type;

    public:
        std::string getType() { return type; };
        virtual std::string toString() = 0;
};

#endif
