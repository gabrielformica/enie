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
#include <vector>

class Function: public Type {
    private:
        Type *ret;
        std::vector<Type *>* params;

    public:
        typedef Type super;

        Function(std::vector<Type *>* tl, Type * ty) : super(0) {
            this->params = tl;
            this->ret = ty;
        }

        void setRetorno(Type *t) { this->ret = t; }
        void addParam(Type *t) { this->params->push_back(t); }
        Type *getRetorno() { return this->ret; }
        std::vector<Type *>* getParams() { return this->params; }

        std::string typeString() {

            std::string str = "function(";

            std::cout << "-----------------" << std::endl;
            std::cout << "HOLS " << params->size() << std::endl;

            for (int i = 0; i < params->size(); ++i) {
                str = str + (*params)[i]->typeString();
                str = str + ", ";
            }
            str = str + "-> ";
            // str = str + ret->typeString();
            str = str + ")";

            return str;
        }
        bool is(std::string t) { return t == "function"; }

        void setByte() { this->bytes = 0; }
};

#endif
