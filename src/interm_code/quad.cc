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
  * Quad class definition
  */

#include <string>
#include "quad.hh"
#include "../nodes/exp.hh"
#include "../symtable/symbol.hh"
#include "../sound_type_system/base/type.hh"

Quad::Quad(std::string op, Argument *a1, Argument *a2, Argument *r) {
    this->op = op;
    this->arg1 = a1;
    this->arg2 = a2;
    this->result = r;
    this->next = NULL;
}

std::string Quad::emit() { 
    std::string str = "--------\n";
    
    str += "operator: " + this->op + "\n";
    str += "arg1 : "; 
    if (this->arg1 != NULL) 
        str += this->arg1->toString();

    str += "\n";
    str += "arg2 : "; 
    if (this->arg2 != NULL)
        str += this->arg2->toString();

    str += "\n";
    str += "result : " + this->result->toString();
    str += "\n--------\n";

    if (this->next != NULL)
        str += this->next->emit();


    return str; 
}

Argument* Quad::getResult() {
    return this->result;
}

Quad* Quad::getNext() {
    return this->next;
}

void Quad::setNext(Quad *q) {
    this->next = q;
}

void Quad::appendToFinal(Quad *q) {
    this->getFinal()->setNext(q);
}

Quad *Quad::getFinal() {
    Quad *temp = this;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    return temp;
}
