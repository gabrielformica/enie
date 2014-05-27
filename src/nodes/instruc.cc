/**
  * Copyright 2014
  *
  * @file instruct.hh
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


#include "instruc.hh"

int Instruc::get_line() {
    return this->line;
}

int Instruc::get_col() {
    return this->col;
}

void Instruc::set_line(int l) {
    this->line = l;
}
void Instruc::set_col(int c) {
    this->col = c;
}
