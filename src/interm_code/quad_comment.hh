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

class QuadComment {
    private:
        int line;              //Line number of the instruction
        std::string inst_name; //Instruction name
    public:

        typedef Quad super;
        /* Class constructor */
        QuadComment(int line) {
            this->line = line;
        }

        /**
          * Emit this
          */
        std::string emit() {
            return std::to_string(line) + "-------> " + this->inst_name;
        }

        
};

#endif
