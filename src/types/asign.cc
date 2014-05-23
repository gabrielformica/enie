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
#include "../symtable.hh"


Symbol* Asign::get_symbol() {
    return this->sym;
}

// Expression* get_expression() {
//     return this->expr;
// }

void Asign::set_symbol(Symbol *s) {
    this->sym = s;
}

// void set_expression(Expression *e) {
//     this->expr = e;
// }

bool Asign::check() {
    std::string exp_type = this->exp->check();
  //  //std::string sym_type = this->sym->getType();

  //  if (sym_type == exp_type) {
  //      return true;
  //  }

    return false;
}
