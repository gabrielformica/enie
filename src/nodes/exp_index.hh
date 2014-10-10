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
  * Class definitions for expressions that are indexed (e.g. x[i])
  */


#ifndef EXP_INDEX_HH
#define EXP_INDEX_HH


#include <string>
#include <vector>
#include "node.hh"
#include "../sound_type_system/base/type.hh"

class ExpIndex: public Exp {
    private:
        std::string id;
        std::vector<Exp *> *explist;

    public:
        typedef Exp super;

        ExpIndex(std::string id, std::vector<Exp *> *explist, Type *t)
                : super(t) {
            
            this->id = id;
            this->explist = explist;
        }

        bool is(std::string str) { return str == "ExpIndex"; }

        std::string toString() {
            std::string str = "Expresion -Indexada-: \n";
            str += this->getUnaryOperator() + this->id;
            
            for (std::vector<Exp *>::iterator it = this->explist->begin();
                    it != this->explist->end(); ++it) {
                
                str += "[" + (*it)->toString()  + "]";
            }

            return str;
        }

        Quad *genCode() { 
            return NULL; 
        }

        Quad *genJumpingCode(std::string a, std::string b) {
            return NULL;
        }

};

#endif
