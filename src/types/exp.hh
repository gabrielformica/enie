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
    private:
        std::string type;

    public:
        explicit Exp(std::string t) : type(t) { }

        std::string getType() { return type; }; 
        //virtual std::string print() = 0;
};

#endif
