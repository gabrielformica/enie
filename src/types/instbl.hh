/**
  * Copyright 2014
  *
  * @file instbl.hh
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for instruction block type
  */

#include "instlist.hh"

#ifndef INSTBL_HH
#define INSTBL_HH


class Instbl {
    private:
        Instlist *listinst;
    public:
        explicit Instbl(Instlist *l) : listinst(l) { }
        Instlist* getInstList() {return this-> listinst;}
};

#endif
