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


#ifndef EXP_RECORD_HH
#define EXP_RECORD_HH


#include <string>
#include <vector>
#include "node.hh"
#include "../sound_type_system/base/type.hh"
#include "../interm_code/quad.hh"
#include "../interm_code/interm_code_helper.hh"

class ExpRecord: public Exp {
    private:
        std::vector<Symbol *> *symlist;

    public:
        typedef Exp super;

        ExpRecord(std::vector<Symbol *> *symlist, Type *t)
                : super(t) {
            this->symlist = symlist;
        }

        bool is(std::string str) { return str == "ExpRecord"; }

        std::string toString() {
            std::string str = "";
            // std::string str = "Expresion -Indexada-: \n";
            // str += this->getUnaryOperator() + this->id->getId();

            // for (std::vector<Exp *>::iterator it = this->explist->begin();
            //         it != this->explist->end(); ++it) {

            //     str += "[" + (*it)->toString()  + "]";
            // }

            return str;
        }

        Type *getType() {
            Symbol *s = this->symlist->back();
            return s->getType();
        }

        Quad *genCode() {
            Quad *code = new Quad(0, "");

            Argument *last_result = NULL;
            std::vector<Symbol *>* syms = this->symlist;
            for (std::vector<Symbol *>::iterator it = syms->begin();
                it != syms->end(); ++it) {

                Symbol *new_temp = get_next_temp();
                std::string offset = std::to_string((*it)->getOffset());
                Argument *result = new ArgumentVar(new_temp, (*it)->getType());
                Argument *off_arg = new ArgumentConst(offset, NULL);

                if (last_result == NULL) {
                    Quad *q1 = new Quad(":=", off_arg, NULL, result);
                    code->appendToFinal(q1);
                }
                else  {
                    Quad *q1 = new Quad("+", off_arg, last_result, result);
                    code->appendToFinal(q1);
                }

                last_result = result;
            }

            Symbol *new_temp = get_next_temp();
            Argument *result = new ArgumentVar(new_temp, NULL);
            std::string str = this->symlist->front()->getId();
            str += "(" + last_result->toString() + ")";
            Argument *indire = new ArgumentConst(str, NULL);

            Quad *q2 = new Quad(":=", indire, NULL, result);
            code->appendToFinal(q2);

            return code;
            // Arreglo *t = (Arreglo *) this->id->getType();
            // comment->appendToFinal((* this->explist)[0]->genCode());
            // for (int i = 1; i < this->explist->size(); i++) {
            //     //Begin Magic
            //     int size = t->getSizeOfDim(i+1);
            //     std::string str_size = std::to_string(size);

            //     Argument *r1 = comment->getFinal()->getResult();
            //     Argument *size_arg = new ArgumentConst(str_size, this->type);

            //     Symbol *new_temp = get_next_temp();
            //     Argument *temp = new ArgumentVar(new_temp, this->type);
            //     Quad *q1 = new Quad("*", r1, size_arg, temp);
            //     //End Magic
            //     comment->appendToFinal(q1);

            //     Argument *r2 = comment->getFinal()->getResult();  //Last result
            //     Quad *exp = (* this->explist)[i]->genCode();
            //     comment->appendToFinal(exp);
            //     Argument *r3 = exp->getFinal()->getResult();

            //     Symbol *new_temp_2 = get_next_temp();
            //     Argument *temp_2 = new ArgumentVar(new_temp_2, this->type);
            //     Quad *q2 = new Quad("+", r2 , r3, temp_2);


            //     comment->appendToFinal(q2);
            // }
        }

        Quad *genJumpingCode(std::string a, std::string b) {
            return NULL;
        }

};

#endif
