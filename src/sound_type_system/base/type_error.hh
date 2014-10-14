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
        int line;
        std::string error;

    public:
        typedef Type super;

        /** class constructor */
        TypeError(std::string error) : super(0) {
            this->error = error;
        }

        TypeError(int line, std::string error) : super(0) {
            this->line = line;
            this->error = error;
        }

        std::string toString() {
            std::string str = "error semantico ";
            str +=  "(linea " + std::to_string(line) + "): ";
            str +=  this->error;
            return str;
        }

        std::string typeString() { return "error"; }
        bool is(std::string t) { return t == "error"; }

        void setWidth() { this->width = 0; }
};

#endif
