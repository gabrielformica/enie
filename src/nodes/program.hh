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
  * Program class definition
  */


#ifndef PROGRAM_HH
#define PROGRAM_HH

#include "node.hh"
#include "func_node.hh"
#include <vector>

class Program: public Node {
    private:
        std::vector<FuncNode *> *func_list;

    public:
        typedef Node super;

        Program(FuncNode *fn) : super(NULL) {
            this->func_list = new std::vector<FuncNode *>;
            this->append(fn);
        }
        
        void append(FuncNode *fn) {
            this->func_list->push_back(fn);
            //this->setType();
        }

        void setType() {
            for (int i = 0; i < this->func_list->size(); i++) {
                if ( (*this->func_list)[i]->getType()->is("error") ) {
                    this->type = (*this->func_list)[i]->getType();
                    break;
                }
            }
        }

        std::string toString() {
            std::string str = "";
            for (int i = 0; i < this->func_list->size(); i++) {
                FuncNode *func = (*this->func_list)[i];
                str = str + func->toString(); 
            }

            return str;
        }

};

#endif
