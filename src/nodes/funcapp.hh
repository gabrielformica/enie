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

};

#endif
