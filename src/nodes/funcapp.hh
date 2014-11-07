/**
  * Copyright 2014
  *
  * @file asign.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for asignment instruction
  *
  */


#ifndef FUNCAPP_HH
#define FUNCAPP_HH

#include "exp.hh"
#include "instruc.hh"
#include "../symtable/symtable.hh"
#include "../interm_code/quad_comment.hh"

class FuncApp: public Exp {
    private:
        std::string id;
        std::vector<Exp *> *params;
        bool retorna = false;

    public:
        typedef Exp super;

        FuncApp(std::string id, std::vector<Exp *> *params, Type *t) :
                     super(t) {

            this->id = id;
            this->params = params;
        }

        FuncApp(std::string id, std::vector<Exp *> *params, Type *t, bool r) :
                     super(t) {

            this->id = id;
            this->params = params;
            this->retorna = r;
        }


        std::string getId() { return this->id; }
        std::vector<Exp *> *getParams() { return this->params; }
        void setRetorna(bool ret) { this->retorna = ret; }
        bool is(std::string str) { return str == "FuncApp"; }

        std::string toString() {
            std::string str = "Llamada a funcion: \n";
            str += "id : " + this->id + "\n";
            str += "parametros : ";

            for (int i = 0; i < this->params->size(); i++) {
                str += "\n" + (*this->params)[i]->toString();
                str += " del tipo '" + (*this->params)[i]->getTypeStr() + "'";
            }

            return str;
        }

        Quad *genCode() {
            Quad *comment = new Quad(0,"");
            std::vector<Quad *> *params_quads = new std::vector<Quad *>;

            Quad *temps = new Quad(0,"");
            //Quads vector of every expression
            for (int i = 0; i < this->params->size(); i++) {
                Quad *resolv_exp = (* this->params)[i]->genCode();
                Argument *arg = resolv_exp->getFinal()->getResult();
                params_quads->push_back(resolv_exp);
                comment->appendToFinal(resolv_exp);
                temps->appendToFinal(new Quad("param", arg, NULL, arg));
            }
            comment->appendToFinal(temps);


            //Connecting the quads and getting the results
            //for (int i = 0; i < params_quads->size(); i++) {
            //    Argument *arg = (* params_quads)[i]->getFinal()->getResult();

            //    comment->appendToFinal(new Quad("param", arg, NULL, arg));
            //}

            int num_param = this->params->size();  //Number of parameters
            std::string num_p = std::to_string(num_param);
            Argument *arg1 = new ArgumentConst(this->id, NULL);
            Argument *arg2 = new ArgumentConst(num_p, NULL);

            if (!this->retorna) {
                comment->appendToFinal(new Quad("call",  arg1, arg2, NULL));
            } else {
                Symbol *temp  = get_next_temp();
                Argument *ret = new ArgumentVar(temp, this->type);
                comment->appendToFinal(new Quad("call",  arg1, arg2, ret));
            }

            return comment;
        }

        Quad *genJumpingCode(std::string true_label, std::string false_label) {
            ArgumentConst *true_arg  = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg  = new ArgumentConst(false_label, NULL);

            Quad *code = this->genCode();
            Argument *func_result = code->getFinal()->getResult();

            if (func_result != NULL) {
                std::string quad_op = func_result->toString();
                Quad *q = NULL;

                if (this->op == "!") {
                    q = new Quad(quad_op, NULL, NULL, false_arg);
                    code->appendToFinal(q);
                    q = new Quad("goto", NULL, NULL, true_arg);
                    code->appendToFinal(q);
                } else {
                    q = new Quad(quad_op, NULL, NULL, true_arg);
                    code->appendToFinal(q);
                    q = new Quad("goto", NULL, NULL, false_arg);
                    code->appendToFinal(q);
                }
            } else {
                ///////////////////////////////////////////////
                // This comment is for pedagogical purposes. //
                ///////////////////////////////////////////////
                // This should never happen because it means you're
                // calling a function that does not return as if it returned
                // bool. Type checking should get care of this.
            }

            return code;
        }
};

#endif
