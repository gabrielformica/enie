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
  * FunctionList class definition
  */


#ifndef FUNCTION_LIST_HH
#define FUNCTION_LIST_HH

#include <list>
#include "function.hh"

class FunctionList {
    private:
        std::list<Function *> *list;
    
    public:
        FunctionList(Function *);
        void append(Function *);
};

#endif
