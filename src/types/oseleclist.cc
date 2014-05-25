/**
  * Copyright 2014
  *
  * @file oseleclist.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class implementations for a list of the else-if part of a selection
  * instruction.
  *
  */

#include <list>
#include "oseleclist.hh"
#include "oselec.hh"

Oseleclist::Oseleclist() {
    std::list<Oselec*> *ltemp = new std::list<Oselec*>;
    this->list = ltemp;
}

Oseleclist::Oseleclist(Oselec *os) {
    std::list<Oselec*> *ltemp = new std::list<Oselec*>;
    this->list = ltemp;
    this->list->push_back(os);
}

std::list<Oselec*>* Oseleclist::getList() {
    return this->list;
}

void Oseleclist::addOselec(Oselec *os) {
    this->list->push_back(os);
}



