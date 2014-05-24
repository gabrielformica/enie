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
#include "instlist.hh"

std::list<Instruc*> Instlist::getList() {
    return this->listinst;
}

