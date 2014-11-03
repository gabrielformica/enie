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


#ifndef UNION_HH
#define UNION_HH

#include <string>
#include <list>
#include "type.hh"
#include "../../symtable/symtable.hh"
#include "../../symtable/symbol.hh"


class Union: public ConstructorType {
    public:
        typedef ConstructorType super;

        /** Class constructor */

        Union() : super() { }

        std::string typeString() { return "union"; }

        bool is(std::string t) { return (t == "union" || t == "constructor"); }

        void setWidth() {
            int max = 0;
            std::list<Symbol *> *list = this->table->getAllSymbols();

            for (std::list<Symbol *>::iterator it = list->begin();
                                     it != list->end(); ++it) {

                if ( (*it)->getType()->getWidth() == 0 )
                    (*it)->getType()->setWidth();

                int temp = (*it)->getType()->getWidth();
                max = max > temp ? max : temp;
            }

            this->width = max;
        }

        void setOffset() { }

};

#endif
