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
  * Header class implementation 
  */


#include "header.hh"


/** Class constructor */

Header::Header(std::string id, Signa *signa) {
    this->id = id;
    this->signa = signa;
}
