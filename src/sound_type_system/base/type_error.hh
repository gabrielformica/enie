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
  * Class definitions for type error
  */


#ifndef TYPE_ERROR_HH
#define TYPE_ERROR_HH

#include "type.hh"

class TypeError: public Type {
    private:
        std::string error;

    public:
        typedef Type super;

        /** class constructor */
        TypeError(std::string error) : super(0) {
            this->error = error;
        }

        std::string typeString() { return "error"; }
        bool is(std::string t) { return t == "error"; }

        void setBytes() { this->bytes = 0; }
};

#endif
