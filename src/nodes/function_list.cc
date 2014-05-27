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


#include <list>
#include "function_list.hh"


/** Class constructor */

FunctionList::FunctionList(Function *function) {
    this->list = new std::list<Function *>;
    this->list->push_back(function);
}


/**
  * Appends a function to the list
  * @param function
  */

void FunctionList::append(Function *function) {
    this->list->push_back(function);
}
