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
  * Basic Block class definition
  */

#ifndef BASIC_BLOCK_HH
#define BASIC_BLOCK_HH

#include "quad.hh"
#include <vector>


class BasicBlock {
    private:
        std::vector<Quad *> *block;

    public:
        BasicBlock();
        BasicBlock(Quad *, Quad *);

        std::vector<Quad *> *getList();
        void addQuad(Quad *);
        void clearFirst();

};



#endif
