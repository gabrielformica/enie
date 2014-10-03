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
  * Class definitions for simple expressions that are a variable
  */

#ifndef EXP_VAR_HH
#define EXP_VAR_HH

class ExpVar: public ExpSimple {
    public:
        typedef ExpSimple super;

        /** Class constructor */
        ExpVar(Type *t) : super(t) { };

        ExpVar(std::string elem, Type *t) : super(elem, t) {}; 

        bool is(std::string str) { return "ExpVar"; }
};

#endif
