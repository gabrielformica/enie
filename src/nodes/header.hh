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
  * Header class definition
  */


#ifndef HEADER_HH
#define HEADER_HH

#include <string>
#include <vector>

class Header: public Node {
    private: 
        std::string id; 

    public:
        typedef Node super;

        Header(std::string id , Type *t) : super(t) {
            this->id = id;
        }

        std::string getId() { return this->id; }

        std::string toString() {
            std::string str = "";
            //std::vector<Type *> *params = ((Function *) this->type)->getParams();

            str =  "nombre: " + id + "\n";  

            return str;
        }

        Quad *genCode() { 
            Argument *label = new ArgumentConst(id, NULL); 
            return new Quad("label", NULL, NULL, label);
        }
};

#endif
