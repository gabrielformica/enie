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
  * SymbolTable class definition (LeBlanc-Cook symbol table)
  */

#ifndef MIPS_HH
#define MIPS_HH
#include <iostream>
#include <string>
#include <vector>
#include "../../interm_code/quad.hh" 
#include "../../symtable/symtable.hh" 
#include "../../symtable/symbol.hh"
#include "../../interm_code/argument.hh"


static int next_str_label = 0;

class MipsInst {
    private:
        std::string op;
        Argument *dest;
        Argument *left;
        Argument *right;
    public:
        MipsInst(Quad *); 
        MipsInst(std::string); 
        std::string getOp();
        Argument *getDest();
        Argument *getLeft();
        Argument *getRight();
        std::string toString();
};

class Mips {
    private:
        std::vector<MipsInst *> *code;
    public:
        Mips(Quad *, SymbolTable *);
        std::string emit();
};

#endif
