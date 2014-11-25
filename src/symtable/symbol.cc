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
#include "../sound_type_system/base/type.hh"

using namespace std;


/** Class constructor */

Symbol::Symbol(std::string id, Type *t, int s, int l, int c) {
    this->id = id;
    this->type = t;
    this->scope = s;
    this->line = l;
    this->column = c;
    this->vars = new std::set<Symbol *>;
}

/** Class constructor */

Symbol::Symbol(std::string id, int s, int l, int c) {
    this->id = id;
    this->scope = s;
    this->line = l;
    this->column = c;
    this->type = NULL;
    this->vars = new std::set<Symbol *>;
}

/** Class constructor with offset */

Symbol::Symbol(std::string id, Type *t, int s, int l, int c, int o) {
    this->id = id;
    this->scope = s;
    this->line = l;
    this->column = c;
    this->offset = o;
    this->type = NULL;
    this->vars = new std::set<Symbol *>;
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

Type *Symbol::getType() {
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
void Symbol::setType(Type *type) {
    this->type = type;
}

int Symbol::getOffset() {
    return this->offset;
}

void Symbol::setOffset(int o) {
    this->offset = o;
}

/* Prints a symbol */
void Symbol::print() {
    std::cout << "Nombre:   " << id << "   ";
    std::cout << "Línea:   " <<  line << "   Columna:   " << column;
    std::cout << " Alcance:   " << scope;
    std::cout << " Offset:   " << offset;
    if (type != NULL) {
        std::cout << " Width:   " << type->getWidth();
        std::cout << " Tipo:    " << type->typeString();
    }

    std::cout << " ";

    for (std::set<Symbol *>::iterator it=vars->begin();
        it!=vars->end();
        it++ ) {
        std::cout << (*it)->getId() << ", ";
    }


    std::cout << " " << std::endl;



}

std::set<Symbol *> *Symbol::getVars() {
    return this->vars;
}

void Symbol::initializeVars() { this->vars = new std::set<Symbol *>; }

Symbol *Symbol::getRegToUse(){
    for (std::set<Symbol *>::iterator it=this->vars->begin();
        it!=this->vars->end(); ++it) {
        if ((*it)->getId().substr(0, 2) == "R_") {
            return (*it);
        }
    }

    return NULL;
}
