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
  * Signa class implementation
  */


#include "signa.hh"
#include "arglist.hh"
#include <string>


/** Class constructor */

Signa::Signa(ArgList *arglist, std::string return_type) {
    this->arglist = arglist;
    this->return_type = return_type;
}
