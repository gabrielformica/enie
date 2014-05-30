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

class Header: public Node {
    private: 
        std::string id; 

    public:
        typedef Node super;

        Header(std::string id , Type *t) : super(t) {
            this->id = id;
        }
};

#endif
