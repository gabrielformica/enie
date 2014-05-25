/**
  * Copyright 2014
  *
  * @file optlist.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for the options of a case instruction
  *
  */

#ifndef OPTTION_HH
#define OPTTION_HH

#include <string>
#include "instbl.hh"
#include "../symtable.hh"

class Option {
    private:
        bool isConstant;
        Instbl *block;
        Symbol *sym;
        std::string cad;
    public:
        Option(Instbl *bl, bool is, Symbol *s, std::string c);
        explicit Option(std::string c);
        explicit Option(Symbol *s);

        void setBlock(Instbl *bl);
};

#endif
