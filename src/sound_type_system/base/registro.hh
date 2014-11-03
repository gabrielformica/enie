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


#ifndef REGISTRO_HH
#define REGISTRO_HH

#include <string>
#include <list>
#include "type.hh"
#include "../../symtable/symtable.hh"
#include "../../symtable/symbol.hh"


class Registro: public ConstructorType {
    public:
        typedef ConstructorType super;

        /** Class constructor */

        Registro() : super() { }

        std::string typeString() { return "registro"; }

        bool is(std::string t) { return (t == "registro" || t == "constructor");}

        void setWidth() {
            int sum = 0;
            std::list<Symbol *> *list = this->table->getAllSymbols();

            for (std::list<Symbol *>::iterator it = list->begin();
                                     it != list->end(); ++it) {

                if ( (*it)->getType()->getWidth() == 0 )
                    (*it)->getType()->setWidth();

                sum = sum + (*it)->getType()->getWidth();
            }

            this->width = sum;
        }

        void setOffset() {
            int offset = 0;
            std::list<Symbol *> *list = this->table->getAllSymbols();

            for (std::list<Symbol *>::iterator it = list->begin();
                                     it != list->end(); ++it) {
                (*it)->setOffset(offset);
                offset += (*it)->getType()->getWidth();
            }
        }

};

#endif
