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
#include "../sound_type_system/base/type.hh"


class InstList : public Instruc {
    private:
        std::list<Instruc *>* list;

    public:
        typedef Instruc super;

        InstList(Instruc *inst, Type *t) : super(t) {
            this->list = new std::list<Instruc *>;
            this->list->push_back(inst);
        }

        void addInst(Instruc *inst) {
            if (inst == NULL) {
                this->list->push_back(NULL);
                this->type = new TypeError("");
            }
            else if (inst->getType()->is("error")) {
                this->list->push_back(inst);
                this->type = inst->getType();
            }
        }
};

#endif
