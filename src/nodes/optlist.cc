/**
  * Copyright 2014
  *
  * @file optlist.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for the list of options of a case instruction
  *
  */

#include <list>
#include "optlist.hh"
#include "option.hh"

Optlist::Optlist(Option *o) {
    std::list<Option*> *l = new std::list<Option*>;
    l->push_back(o);
    this->list = l;
}

void Optlist::addOption(Option *o) {
    this->list->push_back(o);
}


