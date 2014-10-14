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

    public:
        typedef Exp super;

        FuncApp(std::string id, std::vector<Exp *> *params, Type *t) : 
                     super(t) { 

            this->id = id;
            this->params = params;
        }

        std::string getId() { return this->id; }
        std::vector<Exp *> *getParams() { return this->params; }

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

            comment->appendToFinal(new Quad("call",  arg1, arg2, NULL));
            return comment; 
        }

        Quad *genJumpingCode(std::string a, std::string b) {
            return NULL;
        }
};

#endif
