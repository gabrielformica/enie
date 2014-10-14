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
  * FuncNode class definition
  */


#ifndef FUNC_NODE_HH
#define FUNC_NODE_HH

#include <string>
#include "header.hh"
#include "instlist.hh"

class FuncNode: public Node  {
    private:
        Header *header;
        InstList *block;

    public:
        typedef Node super;

        FuncNode(Header *header, InstList *block) : super(NULL) {
            this->header = header;
            this->block = block;
            this->setType();
        }

        void setType() {
            this->type = this->header->getType(); 
            if (this->block != NULL)  {
                if (this->block->getType()->is("error")) {
                    this->type = this->block->getType();
                }
            }
        }

        std::string toString() {
            std::string str = "Funcion\n"; 
            str = str + this->header->toString();

            if (this->block == NULL) {     //It's a forward declaration
                str += "FORWARD DECLARATION\n";
            }
            else {
                str += "Bloque de instrucciones:\n"; 
                str +=  this->block->toString();
            }

            return str;
        }

        Quad *genCode() { 
            Quad *comment = new Quad(0,"");
            comment->appendToFinal(this->header->genCode());
            comment->appendToFinal(this->block->genCode());
            return comment;
        }

};

#endif
