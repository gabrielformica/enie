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
  * Keeps track of the current temp
  */

#ifndef INTERM_CODE_HELPER_HH
#define INTERM_CODE_HELPER_HH

#include <string>
#include "quad.hh"
#include "basic_block.hh"
#include "../symtable/symbol.hh"
#include "../symtable/symtable.hh"

extern SymbolTable *symtable;

static int next_temp = 0;
static int next_label = 0;

Symbol *get_next_temp();
std::string get_next_label();

void gen_un_op(Quad *q, std::string un_op);

std::vector<BasicBlock *> *genBasicBlocks(Quad *);

#endif
