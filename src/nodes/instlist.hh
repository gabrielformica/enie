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


class Instlist : public Instruc {
    private:
        std::list<Instruc *>* list;

    public:
        typedef Instruc super;

        Instlist(Instruc *inst, Type *t ) : super(t) {
            this->list = new std::list<Instruc *>;
            this->list->push_back(inst);
        }

        std::list<Instruc *> getList();

        void addInst(Instruc *inst) {
            if (inst->getType()->is("error")) {
                this->type = inst->getType();
            }

            this->list->push_back(inst);
        }
};

#endif
