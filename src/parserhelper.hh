#ifndef PARSERHELPER_HH
#define PARSERHELPER_HH

#include <iostream>
#include <string>
#include "symtable/symtable.hh"
#include "symtable/symbol.hh"
#include "nodes/exp.hh"
#include <vector>

void tryAddSymbol(SymbolTable *, std::vector<std::string> *, Symbol *);

std::vector<Type *> *getTypesFromExps(std::vector<Exp *> *exps); 

#endif
