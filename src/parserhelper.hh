#ifndef PARSERHELPER_HH
#define PARSERHELPER_HH

#include <iostream>
#include <string>
#include "symtable/symtable.hh"
#include "symtable/symbol.hh"
#include "nodes/exp.hh"
#include "nodes/program.hh"
#include "nodes/node.hh"
#include "mips_code/mips_program.hh"
#include <vector>

void tryAddSymbol(SymbolTable *, std::vector<std::string> *, Symbol *);

std::vector<Type *> *getTypesFromExps(std::vector<Exp *> *exps);

std::string not_implemented(SymbolTable *symtable);

void getReg(Quad *, SymbolTable *, MipsProgram *);

Symbol *getRegAux(Argument *, Symbol *, SymbolTable *, MipsProgram *);

void store_them(Symbol *, MipsProgram *);

void addRegisters(SymbolTable *, Type *);


#endif
