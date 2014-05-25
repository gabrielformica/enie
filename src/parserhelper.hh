#ifndef PARSERHELER_HH
#define PARSERHELPER_HH
#include <vector>
#include <string>
#include <iostream>
#include "symtable.hh"

void tryAddSymbol(SymbolTable *, std::vector<std::string> *, Symbol *);
void checkUse(SymbolTable *, std::vector<std::string> *, Symbol *);
#endif
