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
  * Header class definition
  */


#ifndef HEADER_HH
#define HEADER_HH

#include <string>
#include "signa.hh"

class Header {
    private: 
        std::string id; 
        Signa *signa;

    public:
        Header(std::string, Signa *);
};

#endif
