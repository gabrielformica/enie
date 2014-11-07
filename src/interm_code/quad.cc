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
    this->line = -1;
    this->comment = "";
}

Quad::Quad(int line, std::string comment) {
    this->op = "";
    this->arg1 = NULL;
    this->arg2 = NULL;
    this->result = NULL;
    this->next = NULL;
    this->line = line;
    this->comment = comment;
}

std::string Quad::emit() {
    std::string str = "";

    if (this->line == 0)
        return this->next->emit();

    if (this->line > 0)  {
        str += "-----> " + this->comment + ", linea ";
        str += std::to_string(this->line) + "<-----\n";
    } else if (this->op == "return") {
        str += "return ";
        if (this->arg1 != NULL)
            str += this->arg1->toString();
        str += "\n";
    }  else if (this->op == "param") {
        str += "param " + this->arg1->toString() + "\n";

    } else if (this->op == "call") {
        if (this->result != NULL) {
            str += this->result->toString() + " := ";
        }
        str += "call " + this->arg1->toString() + ", ";
        str += this->arg2->toString() + "\n";
    } else if (this->op == "label") {   // Emit for label instruction
        str += this->result->toString() + ": \n";
    // Emit for goto instruction
    } else if (this->op == "goto") {
        str += "goto ";
        str += this->result->toString() + "\n";

    // Emit for assignment instruction
    } else if (this->op == ":=") {

        // Constant quads are for data structure purposes only
        // this can be ignored during the code emision
        if (this->arg1->toString() != this->result->toString()) {
            str += this->result->toString() + " ";
            str += this->op + " ";
            str += this->arg1->toString() + " \n";
        }

    // Emit  for assignment like result[arg1] = arg2
    } else if (this->op == "[]=") {
        str += this->result->toString() + "[" + this->arg1->toString() + "]";
        str += " := " + this->arg2->toString() + "\n";

    } else if (this->op == "=[]") {
        str += this->result->toString() + " := " + this->arg1->toString();
        str += "[" + this->arg2->toString() + "]" + "\n";

    // Emit for relational expression instruction
    } else if (this->op == "<" || this->op == "<=" ||
               this->op == ">" || this->op == ">=" ||
               this->op == "==" || this->op == "!=") {
        str += "if " + this->arg1->toString();
        str += " " + this->op;
        str += " " + this->arg2->toString();
        str += " then goto";
        str += " " + this->result->toString() +"\n";

    } else if (this->op[0] == '_' || this->op[0] == '$') {

        if (this->op[0] == '_') {
            str += "if " + this->op.substr(1);
        } else {
            str += "if " + this->op;
        }
        str += " then goto";
        str += " " + this->result->toString() +"\n";


    // Omit for comments (this should be implemented later)
    } else if (this->result == NULL) {

    // Emit for algebraic operations (hopefully)
    } else {
        if (this->arg2 == NULL) {  // Unary operand and i
            if ((this->op == "!") || (this->op == "-")) {
                str += this->result->toString() + " := ";
                str += this->op + this->arg1->toString() + "\n";
            }
        }
        else {
            if (this->result != NULL)
                str += this->result->toString() + " := ";

            if (this->arg1 != NULL)
                str += this->arg1->toString() + " ";

            str += this->op + " ";

            if (this->arg2 != NULL)
                str += this->arg2->toString() + "\n";
        }
    }

    // Recursive call
    if (this->next != NULL)
        str += this->next->emit();

    return str;
}

Argument* Quad::getResult() {
    return this->result;
}

Argument* Quad::getArg1() {
    return this->arg1;
}

Argument* Quad::getArg2() {
    return this->arg2;
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

void Quad::clean() {
    Quad *temp = this;
    while (temp->next != this->getFinal()) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void Quad::setLine(int l) {
    this->line = l;
}

Quad *Quad::getFinal() {
    Quad *temp = this;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    return temp;
}
