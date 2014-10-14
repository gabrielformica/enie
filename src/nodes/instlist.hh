/**
  * Copyright 2014
  *
  * @file instlist.hh
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for base instruction type
  * Basicamente funciona como clase base para el diverso conjunto de
  * instrucciones existentes.
  */


#ifndef INSTLIST_HH
#define INSTLIST_HH

#include <list>
#include "instruc.hh"
#include "../sound_type_system/base/type_error.hh"
#include "../sound_type_system/base/type.hh"
#include "../interm_code/quad.hh"
#include "../interm_code/quad_comment.hh"

class InstList : public Instruc {
    private:
        std::vector<Instruc *>* list;

    public:
        typedef Instruc super;

        InstList(Instruc *inst, Type *t) : super(t) {
            this->list = new std::vector<Instruc *>;
            this->list->push_back(inst);
        }

        void addInst(Instruc *inst) {
            if (inst == NULL) {
                this->list->push_back(NULL);
                this->type = new TypeError("");
            }
            else {
                this->list->push_back(inst);
                if (inst->getType()->is("error"))
                    this->type = inst->getType();
            }
        }

        std::string toString() {
            std::string str = "";
            for (int i = 0; i < this->list->size(); i++) {
                str = str + (*this->list)[i]->toString() + "\n";
            }
            return str;
        }

        Quad *genCode() {
            std::vector<Instruc *>* inst_list = this->list;
            Quad *inst_quad = new Quad(0,"");
            for (std::vector<Instruc *>::iterator it = inst_list->begin();
                it != inst_list->end(); ++it) {
                Quad *inst = (*it)->genCode();
                inst_quad->appendToFinal(inst);
            }

            return inst_quad;
        };
};

#endif
