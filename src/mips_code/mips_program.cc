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
  * MIPS Program class implementation
  */


#include "mips_program.hh"

MipsProgram::MipsProgram() {
    this->program = new std::vector<MipsInst *>;
}

std::string MipsProgram::emit() {
    std::string code = "";

    for (std::vector<MipsInst *>::iterator it = this->program->begin();
        it != this->program->end(); it++) {

        code += (*it)->toString();
        code += "\n";
    }

    return code;
}

