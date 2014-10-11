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
    std::string str = "";

    // Emit for label instruction
    if (this->op == "label") {
        str += this->result->toString() + ": \n";

    // Emit for goto instruction
    } else if (this->op == "goto") {
        str += "goto ";
        str += this->result->toString() + "\n";

    // Emit for assignment instruction
    } else if (this->op == ":=") {
        str += this->result->toString() + " ";
        str += this->op + " ";
        str += this->arg1->toString() + " \n";

    // Emit for assignment instruction
    } else if (this->op == "blt" || this->op == "ble" ||
               this->op == "bgt" || this->op == "bge" ||
               this->op == "beq" || this->op == "bne") {
        str += "if " + this->arg1->toString();
        str += " " + this->op;
        str += " " + this->arg2->toString();
        str += " then goto";
        str += " " + this->result->toString() +"\n";

    // Omit for comments (this should be implemented later)
    } else if (this->op == "") {

    // Emit for algebraic operations (hopefully)
    } else {

        if (this->result != NULL)
            str += this->result->toString() + " := ";

        if (this->arg1 != NULL)
            str += this->arg1->toString() + " ";

        str += this->op + " ";

        if (this->arg2 != NULL)
            str += this->arg2->toString() + "\n";
    }

    // Recursive call
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
