/**
  * Copyright 2014
  *
  * @file arreglo.hh
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for integer type
  */


#ifndef ARREGLO_HH
#define ARREGLO_HH

#include "indexlist.hh"
#include "id.hh"

class Arreglo: public Exp {
    private:
        Id *id;
        Indexlist *list;
    public:
        /** class constructor */
        Arreglo()
        Arreglo(Id *i, Indexlist *l);
};

#endif
