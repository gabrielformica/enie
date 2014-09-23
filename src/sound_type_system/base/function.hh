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
        std::vector<Type *> *params;
        bool forward = true;         //True by default

    public:
        typedef Type super;

        Function(std::vector<Type *>* tl, Type * ty) : super(0) {
            this->params = tl;
            this->ret = ty;
            this->forward = true;     //True by default
        }

        Function(std::vector<Type *>* tl, Type * ty, bool p) : super(0) {
            this->params = tl;
            this->ret = ty;
            this->forward = p;
        }

        void setRet(Type *t) { this->ret = t; }
        Type *getRetType() { return this->ret; }

        bool getForward() { return this->forward; }
        void unsetForward() { this->forward = false; }

        void addParam(Type *t) { this->params->push_back(t); }
        std::vector<Type *>* getParams() { return this->params; }

        bool is(std::string t) { return t == "function"; }

        std::string typeString() {

            std::string str = "function(";

            for (int i = 0; i < params->size(); ++i) {
                str = str + (*params)[i]->typeString();
                str = str + ", ";
            }
            str.erase(str.size()-2, 2);
            str = str + " -> ";
            str = str + ret->typeString();
            str = str + ")";

            return str;
        }

        void setByte() { this->width = 0; }

};

#endif
