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
  * Class definition for a list of the else-if part of a selection instruction.
  *
  */

#ifndef OSELECLIST_HH
#define OSELECLIST_HH

#include <list>
#include "oselec.hh"

class Oseleclist {
    private:
        std::list<Oselec*> list;
    public:
        typedef Instruc super;

        explicit Oseleclist(Oselec *os) {
            std::list<Oselec *> l(1, os);
            this->list = l;
        }

        std::list<Oselec*> getList() { return this->list; }
        void addOselec(Oselec *os) { this->list.push_back(os); }
};

#endif
