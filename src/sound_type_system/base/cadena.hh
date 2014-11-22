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
  * Class definitions for cadena type
  *
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef CADENA_HH
#define CADENA_HH

#include <string>
#include "type.hh"

class Cadena: public Type {
    private:
        std::string str;
    public:
        typedef Type super;

        /** class constructor */
        Cadena() : super(4) { }
        Cadena(std::string s) : super(4) { this->str = s; }

        std::string typeString() { return "cadena"; }
        std::string getStr() { return this->str; }
        bool is(std::string t) { return t == "cadena"; }
        void setWidth() { this->width = str.size(); }
        void setStr(std::string s) {
            this->str = s;
        }
};

#endif
