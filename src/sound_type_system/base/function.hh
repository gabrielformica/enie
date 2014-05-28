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
  * Function class definition
  */


#ifndef FUNCTION_HH
#define FUNCTION_HH

#include <string>
#include <list>

class Function: public Type {
    private:
        Type *retorno;
        std::vector<Type *>* params;

    public:
        typedef Type super;

        Function() : super(0) {
            this->params = new std::vector<Type *>;
        }

        void setRetorno(Type *t) { this->retorno = t; }
        void addParam(Type *t) { this->params->push_back(t); }
        Type *getRetorno() { return this->retorno; }
        std::vector<Type *>* getParams() { return this->params; }
};

#endif
