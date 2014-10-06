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
  * It just represents a comment (e.g. the line of the instruction)
  */


#ifndef QUAD_ASIGN_HH
#define QUAD_ASIGN_HH

#include <string>
#include "quad.hh"
#include "quad_utils.hh"

class QuadComment: public Quad {
    private:
        int line;        //Line number of the instruction
    public:

        /**
          * Returns the string representation of the quad
          */
        std::string toString() {
            return std::to_string(line) + " -------";
        }
};

#endif
