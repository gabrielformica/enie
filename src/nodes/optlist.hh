/**
  * Copyright 2014
  *
  * @file optlist.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for the list of options of a case instruction
  *
  */

#ifndef OPTLIST_HH
#define OPTLIST_HH

#include <list>
#include "option.hh"
#include "../interm_code/interm_code_helper.hh"
#include "../interm_code/quad.hh"


class Optlist {
    private:
        std::list<Option*>* list;
    public:
        Optlist(Option *o);

        void addOption(Option *o);

        Quad *genCode(Argument *exit_arg) {

        }

};

#endif
