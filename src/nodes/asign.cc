/**
  * Copyright 2014
  *
  * @file asign.cc
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for asignment instruction type
  *
  */

#include <string>
#include "asign.hh"
#include "exp.hh"
#include "../symtable/symtable.hh"

Asign::Asign(Symbol *s, Exp *e) {
    this->exp = e;
    this->sym = s;
}

Symbol* Asign::get_symbol() {
    return this->sym;
}

// Expression* get_expression() {
//     return this->expr;
// }

void Asign::setSymbol(Symbol *s) {
    this->sym = s;
}

void Asign::setExpression(Exp *e) {
    this->exp = e;
}

bool Asign::check() {
    std::string exp_type = this->exp->getType();
    std::string sym_type = this->sym->getType();

   if (sym_type == exp_type) {
       return true;
   }

    return false;
}
