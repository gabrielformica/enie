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

#include <string>
#include "interm_code_helper.hh"
#include "../symtable/symbol.hh"

Symbol *get_next_temp() { 
    int next = next_temp++;
    std::string id = "@t" + std::to_string(next);
    Symbol *next_temp_symbol = new Symbol(id,0,0,0);
    return next_temp_symbol;
}

void gen_un_op(Quad *q, std::string un_op) {
    if (un_op == "-" || un_op == "!") {
        Symbol *temp = get_next_temp();
        Argument *result = new ArgumentVar(temp, q->getResult()->getType());

        Quad *next = new Quad(un_op, q->getResult(), NULL, result);
                            
        q->appendToFinal(next);
    }
}


