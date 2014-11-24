 /*
  * Copyright 2014
  *
  * @file
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * MIPS Instruction class implementation
  */

#include "mips_inst.hh"

Add::Add(std::string z, std::string x, std::string y) {
    this->res = z;
    this->arg1 = x;
    this->arg2 = y;
}

std::string Add::toString() {
    std::string str = "";
    str += "add " + res +  ", " + arg1 + ", " + arg2;
    return str;
}

AddI::AddI(std::string z, std::string x, int i) {
    this->res  = z;
    this->arg1 = x;
    this->arg2 = i; // this is an imm
}

std::string AddI::toString() {
    std::string str = "";
    str += "addi " + this->res +  ", " + this->arg1 + ", ";
    str += std::to_string(this->arg2);
    return str;
}


Sub::Sub(std::string z, std::string x, std::string y) {
    this->arg1 = x;
    this->arg2 = y;
    this->res  = z;
}

std::string Sub::toString() {
    std::string str = "";
    str += "sub " + this->res +  ", " + this->arg1 + ", " + this->arg2;
    return str;
}


Mult::Mult(std::string x, std::string y) {
    this->arg1 = x;
    this->arg2 = y;
}

std::string Mult::toString() {
    std::string str = "";
    str += "mult " + this->arg1 + ", " + this->arg2;
    return str;
}


Div::Div(std::string x, std::string y) {
    this->arg1 = x;
    this->arg2 = y;
}

std::string Div::toString() {
    std::string str = "";
    str += "div " + this->arg1 + ", " + this->arg2;
    return str;
}


Mfhi::Mfhi(std::string x) {
    this->arg1 = x;
}

std::string Mfhi::toString() {
    std::string str = "";
    str += "mfhi " + this->arg1;
    return str;
}


Mflo::Mflo(std::string x) {
    this->arg1 = x;
}

std::string Mflo::toString() {
    std::string str = "";
    str += "mflo " + this->arg1;
    return str;
}

Move::Move(std::string a1, std::string r) {
    this->arg1 = a1;
    this->res  = r;
}

std::string Move::toString() {
    std::string str = "";
    str += "move " + this->arg1 + ", " + this->res;
    return str;
}

Jump::Jump(std::string l) {
    this->label = l;
}

std::string Jump::toString() {
    std::string str = "";
    str += "j " + this->label;
    return str;
}

Beq::Beq(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Beq::toString() {
    std::string str = "";
    str += "beq " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Bne::Bne(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Bne::toString() {
    std::string str = "";
    str += "bne " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Bge::Bge(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Bge::toString() {
    std::string str = "";
    str += "bge " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Bgt::Bgt(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Bgt::toString() {
    std::string str = "";
    str += "bgt " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Ble::Ble(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Ble::toString() {
    std::string str = "";
    str += "ble " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Blt::Blt(std::string a1, std::string a2, std::string l) {
    this->arg1 = a1;
    this->arg2 = a2;
    this->label = l;
}

std::string Blt::toString() {
    std::string str = "";
    str += "blt " + this->arg1 + ", " + this->arg2 + ", " + this->label;
    return str;
}

Lw::Lw(std::string a1, std::string d) {
    this->arg1 = a1;
    this->dir = d;
}

std::string Lw::toString() {
    std::string str = "";
    str += "lw " + this->arg1 + ", " + this->dir;
    return str;
}

Sw::Sw(std::string a1, std::string d) {
    this->arg1 = a1;
    this->dir = d;
}

std::string Sw::toString() {
    std::string str = "";
    str += "sw " + this->arg1 + ", " + this->dir;
    return str;
}


