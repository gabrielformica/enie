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

#include "mips.hh"
MipsInst::MipsInst(Quad *quad) {
    std::string q_op = quad->getOp();
    if (q_op == "+") { this->op = "add"; }
    else if (q_op == "-") { this->op = "sub"; }
    else if (q_op == "*") { this->op = "mult"; }
    else if (q_op == "/") { this->op = "div"; }
    else if (q_op == "&") { this->op = "and"; }
    else if (q_op == "|") { this->op = "or"; }

    this->dest = quad->getResult();
    this->left = quad->getArg1();
    this->right = quad->getArg2();
}

MipsInst::MipsInst(std::string area) {
    this->op = area;
    this->dest = NULL;
    this->left = NULL;
    this->right = NULL;
}

std::string MipsInst::toString() {
    std::string str = "";
    str += this->op + " ";
    str += this->dest != NULL ? this->dest->toString() : "";
    str += this->left != NULL ? this->left->toString() : "";
    str += this->right != NULL ? this->right->toString() : "";
    return str;
}

std::string MipsInst::getOp() { return this->op; }
Argument *MipsInst::getDest() { return this->dest; }
Argument *MipsInst::getLeft() { return this->left; }
Argument *MipsInst::getRight() { return this->right; }


Mips::Mips(Quad *interm_code, SymbolTable *symtable) {
    this->code = new std::vector<MipsInst *>;
    Quad *temp = interm_code;
    //set .data
    this->code->push_back(new MipsInst(".data"));
    std::vector<std::string> *asciiz = symtable->getAllStrings();
    for (std::vector<std::string>::iterator it=asciiz->begin(); it!=asciiz->end(); ++it) {  
        std::string data = std::to_string(next_str_label++) + " .asciiz " + (*it); 
        this->code->push_back(new MipsInst(data));
    }
   
    //set .text
    this->code->push_back(new MipsInst(".text"));
    while (temp != NULL) {
        if (! temp->isComment()) 
            this->code->push_back(new MipsInst(temp));

        temp = temp->getNext();
    }
}

std::string Mips::emit() {
    std::string str = "";
    std::vector<MipsInst *>::iterator it;
    for (it=this->code->begin(); it!=this->code->end(); ++it) {
        str += (*it)->toString();
    }
    return str;
}
