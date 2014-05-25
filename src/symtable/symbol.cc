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
  * Symbol class implementation 
  */


#include <iostream>
#include <string>
#include <unordered_map>
#include "symbol.hh"

using namespace std;


/** Class constructor */

Symbol::Symbol(std::string id, std::string t, int s, int l, int c) {
    this->id = id;
    this->type = t;
    this->scope = s;
    this->line = l;
    this->column = c;
}

/** Class constructor */

Symbol::Symbol(std::string id, int s, int l, int c) {
    this->id = id;
    this->scope = s;
    this->line = l;
    this->column = c;
}

/* Return id of the symbol */

string Symbol::getId() {
    return this->id;
}

/* Return scope of the symbol*/

int Symbol::getScope() {
    return this->scope;
}

/* Return line of the symbol*/

int Symbol::getLine() {
    return this->line;
}

/* Return column of the symbol*/

int Symbol::getColumn() {
    return this->column;
}

/* Return column of the symbol*/

string Symbol::getType() {
    return this->type;
}

/* Set scope*/

void Symbol::setScope(int x) {
    this->scope = x;
}

/* Set line*/
void Symbol::setLine(int x) {
    this->line = x;
}

/* Set column*/
void Symbol::setColumn(int x) {
    this->column = x;
}

/* Set Type*/
void Symbol::setType(std::string type) {
    this->type = type;
}

/* Prints a symbol */
void Symbol::print() {
    std::cout << "Nombre:   " << id << "   ";
    std::cout << "Línea:   " <<  line << "   Columna:   " << column;
    std::cout << " Alcance:   " << scope << std::endl;
}
