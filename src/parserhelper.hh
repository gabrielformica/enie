#ifndef PARSERHELER_HH
#define PARSERHELPER_HH

#include <iostream>
#include <string>
#include "symtable/symtable.hh"
#include <vector>

void tryAddSymbol(SymbolTable *, std::vector<std::string> *, Symbol *);
void checkUse(SymbolTable *, std::vector<std::string> *, Symbol *);
#endif
