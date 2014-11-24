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
  * MIPS Program class definition
  */

#ifndef MIPS_PROGRAM_HH
#define MIPS_PROGRAM_HH

#include <vector>
#include <string>
#include "mips_inst.hh"

class MipsProgram {
    private:
        std::vector<MipsInst *> *program;
    public:
        MipsProgram();

        std::vector<MipsInst *> *getList();
        std::string emit();
};

#endif
