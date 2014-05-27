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


#ifndef ARGLIST_HH
#define ARGLIST_HH

#include <list>
#include <string>
#include "../symtable/symbol.hh"


class ArgList {
    private:
        std::list<Symbol *> *list;

    public:
        ArgList();
        ArgList(Symbol *);
        void append(Symbol *);
        
};

#endif
