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
  * THIS IS A PRIMITIVE TYPE
  */


#ifndef ARREGLO_HH
#define ARREGLO_HH

#include <string>
#include "type.hh"

class Arreglo: public Type {
    private:
        Type *type_elem;
        int first_index;
        int last_index;
    public:
        typedef Type super;

        /** Class constructor */
        Arreglo(Type *t, int fi, int li) : super(0) {
            this->type_elem = t;
            this->first_index = fi;
            this->last_index = li;
         }

        std::string typeString() { 
            std::string str;
            str = "arreglo(" + std::to_string(first_index) + ".."; 
            str = str + std::to_string(last_index);
            std::string str1 = "NULL";
            if (this->type_elem != NULL) {
                str1 = this->type_elem->typeString();
            }
            str = str + ", " + str1 + ")";
            return str;
        }

        void setRootTypeElem(Type *type) {
            Type *temp = this->type_elem;
            
            if (temp == NULL) {
                this->type_elem = type; 
                return;
            }

            while (((Arreglo *) temp)->getTypeElem() != NULL) 
                temp = ((Arreglo *) temp)->getTypeElem();

            ((Arreglo *) temp)->type_elem = type;

        }

        Type *getTypeElem() { return this->type_elem; }



};

#endif
