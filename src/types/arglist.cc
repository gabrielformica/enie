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
  * Arglist class definition
  */


#include <list>
#include <string>
#include "arglist.hh"
#include "../symtable/symbol.hh"


/** Class constructor */

ArgList::ArgList() {
    std::list<Symbol *> *list = new std::list<Symbol *>;
    this->list = list;
}


/** Class constructor */

ArgList::ArgList(Symbol *first) {
    std::list<Symbol *> *list = new std::list<Symbol *>;
    list->push_back(first);
    this->list = list;
}


/**
  * Adds new symbol to arglits
  * @param sym : pointer to the new symbol
  */

void ArgList::append(Symbol *sym) {
    this->list->push_back(sym);
}
