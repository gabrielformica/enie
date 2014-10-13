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
        int size;

    public:
        typedef Type super;

        /** Class constructor */
        Arreglo(Type *t, int size) : super(0) {
            this->type_elem = t;
            this->size = size;
         }

        std::string typeString() {
            std::string str;
            str = "arreglo(" + std::to_string(size);
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

        int getSize() { return this->size; }

        bool is(std::string t) { return t == "arreglo"; }

        void setWidth() {
            Type *t = this->type_elem;

            if (t->getWidth() == 0)
                t->setWidth();

            this->width = this->size * t->getWidth();
        }

        int getDimensions() {
            if (! this->type_elem->is("arreglo"))
                return 1;


            return 1 + ((Arreglo *) this->type_elem)->getDimensions();
        }

        int getSizeOfDim(int dimensions) {
            if (dimensions > this->getDimensions()) 
                return 0;

            Arreglo *t = this;
            while (dimensions-- > 1) 
                t = (Arreglo *) t->getTypeElem();

            return t->getSize();
        }

        Type *getRootType() {
            if (! this->type_elem->is("arreglo"))
                return this->type_elem;

            return ((Arreglo *) this->type_elem)->getRootType();
        }
};

#endif
