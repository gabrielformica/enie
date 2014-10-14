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
        std::vector<Node *> *node_list;

    public:
        typedef Node super;

        Program(Node *node) : super(NULL) {
            this->node_list = new std::vector<Node *>;
            this->append(node);
        }
        
        void append(Node *node) {
            this->node_list->push_back(node);
            //this->setType();
        }

        void setType() {
            for (int i = 0; i < this->node_list->size(); i++) {
                if ( (*this->node_list)[i]->getType()->is("error") ) {
                    this->type = (*this->node_list)[i]->getType();
                    break;
                }
            }
        }

        std::string toString() {
            std::string str = "\n--------- AST ---------\n";
            for (int i = 0; i < this->node_list->size(); i++) {
                Node *node = (*this->node_list)[i];
                str = str + node->toString(); 
            }

            str += "--------- AST ----------";

            return str;
        }

        Quad *genCode() {
            Quad *comment = new Quad(0, "");
            Argument *enie = new ArgumentConst("enie", NULL);
            comment->appendToFinal(new Quad("goto", NULL, NULL, enie));
            for (int i = 0; i < this->node_list->size(); i++)
                comment->appendToFinal((* this->node_list)[i]->genCode());

            return comment;
        }

};

#endif
