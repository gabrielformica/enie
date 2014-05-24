/**
  * Copyright 2014
  *
  * @file instlist.hh
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for base instruction type
  * Basicamente funciona como clase base para el diverso conjunto de
  * instrucciones existentes.
  */

#include <list>
#include "instruc.hh"

#ifndef INSTLIST_HH
#define INSTLIST_HH


class Instlist {
    private:
        std::list<Instruc*> listinst;
    public:
        explicit Instlist(Instruc *a) {
            std::list<Instruc*> l(1,a);
            this->listinst = l;
        }

        std::list<Instruc*> getList();
};

#endif
