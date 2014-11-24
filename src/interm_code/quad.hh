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
  * Quad class definition
  */

#ifndef QUAD_HH
#define QUAD_HH

#include <string>
#include "../symtable/symbol.hh"
#include "../sound_type_system/base/type.hh"
#include "argument.hh"

class Quad {
    private:
        int line; //Just for comments
        std::string comment;
        std::string op;
        Argument *arg1;
        Argument *arg2;
        Argument *result;
        Quad *next;

    public:
        Quad(int line, std::string comment);  //Just for comments
        Quad(std::string op, Argument *a1, Argument *a2, Argument *r);
        std::string emit();
        Argument *getResult();
        Argument *getArg1();
        Argument *getArg2();
        std::string getOp();
        Quad *getNext();
        Quad *getFinal();
        bool isComment();
        void clearComments();
        void setLine(int l);
        int getLine();
        void setNext(Quad *q);
        void appendToFinal(Quad *q);
        void clean();
        bool zxy();
        bool isCopy();
};

#endif
