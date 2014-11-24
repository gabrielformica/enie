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

#include "basic_block.hh"

BasicBlock::BasicBlock() {
    this->block = new std::vector<Quad *>;
}

BasicBlock::BasicBlock(Quad *first, Quad *last) {
    this->block = new std::vector<Quad *>;

    if (first == last) {
        this->block->push_back(first);
    } else {

        Quad *next = first;
        // Add first quad to block
        this->block->push_back(first);

        // Add all quads until the next one is the last one
        next = first->getNext();

        while (next != NULL && next != last) {
            this->block->push_back(next);
            next = next->getNext();
        }

        // Add last quad to block
        this->block->push_back(last);
    }


}

std::vector<Quad *> *BasicBlock::getList() {
    return this->block;
}

void BasicBlock::addQuad(Quad *q) {
    this->block->push_back(q);
}

void BasicBlock::clearFirst() {
    Quad *q = this->block->front();

    if (q->getLine() == 0 || q->getLine() > 0) {
        this->block->erase(this->block->begin());
    }
}


