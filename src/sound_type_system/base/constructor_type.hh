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
  * Class definitions for integer type 
  *
  * THIS IS A USER CONSTRUCTOR TYPE
  */


#ifndef CONSTRUCTOR_TYPE_HH
#define CONSTRUCTOR_TYPE_HH

#include <string>
#include <list>
#include "type.hh"
#include "../../symtable/symtable.hh"
#include "../../symtable/symbol.hh"


class ConstructorType: public Type {
    protected:
        SymbolTable *table;

    public:
        typedef Type super;

        /** Class constructor */

        ConstructorType() : super(0) {
            this->table = new SymbolTable();
        }

        void setSymbolTable(SymbolTable *symtable) { this->table = symtable; }

        virtual std::string typeString() = 0;
        virtual bool is(std::string) = 0;

};

#endif
