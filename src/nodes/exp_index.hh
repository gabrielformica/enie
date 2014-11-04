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
        Symbol *var;
        std::vector<Exp *> *explist;

    public:
        typedef Exp super;

        ExpIndex(Symbol *var, std::vector<Exp *> *explist, Type *t)
                : super(t) {

            this->var = var;
            this->explist = explist;
        }

        bool is(std::string str) { return str == "ExpIndex"; }

        std::string toString() {
            std::string str = "Expresion -Indexada-: \n";
            str += this->getUnaryOperator() + this->var->getId();

            for (std::vector<Exp *>::iterator it = this->explist->begin();
                    it != this->explist->end(); ++it) {

                str += "[" + (*it)->toString()  + "]";
            }

            return str;
        }

        Quad *genCode() {
            Quad *comment = new Quad(0,"");
            Arreglo *t = (Arreglo *) this->var->getType();
            comment->appendToFinal((* this->explist)[0]->genCode());
            for (int i = 1; i < this->explist->size(); i++) {
                //Begin Magic
                int size = t->getSizeOfDim(i+1);
                std::string str_size = std::to_string(size);

                Argument *r1 = comment->getFinal()->getResult();
                Argument *size_arg = new ArgumentConst(str_size, this->type);

                Symbol *new_temp = get_next_temp();
                Argument *temp = new ArgumentVar(new_temp, this->type);
                Quad *q1 = new Quad("*", r1, size_arg, temp);
                //End Magic
                comment->appendToFinal(q1);

                Argument *r2 = comment->getFinal()->getResult();  //Last result
                Quad *exp = (* this->explist)[i]->genCode();
                comment->appendToFinal(exp);
                Argument *r3 = exp->getFinal()->getResult();

                Symbol *new_temp_2 = get_next_temp();
                Argument *temp_2 = new ArgumentVar(new_temp_2, this->type);
                Quad *q2 = new Quad("+", r2 , r3, temp_2);


                comment->appendToFinal(q2);
            }
            // Last quad has to be t(i) := a[@t(i-1)]
            Symbol *t1 = get_next_temp();
            Argument *result = new ArgumentVar(t1, this->type);
            Argument *s = new ArgumentVar(this->var, this->type);
            Quad *last = new Quad("=[]",
                                    s,
                                    comment->getFinal()->getResult(),
                                    result);

            comment->appendToFinal(last);
            return comment;
        }

        Symbol *getVar() { return this->var; }
        Quad *genJumpingCode(std::string a, std::string b) {
            return NULL;
        }

};

#endif
