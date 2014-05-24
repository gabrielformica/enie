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
        std::list<Oselec*> *list;
    public:
        typedef Instruc super;

        Oseleclist();
        Oseleclist(Oselec *os);

        std::list<Oselec*>* getList();
        void addOselec(Oselec *os);
};

#endif
