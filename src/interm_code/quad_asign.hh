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
  * Quad assignment class definition
  */

#ifndef QUAD_ASIGN_HH
#define QUAD_ASIGN_HH

#include <string>
#include "quad.hh"
#include "quad_utils.hh"
#include "../symtable/symbol.hh"
#include "../sound_type_system/base/type.hh"

class QuadAsign: public Quad {
    private:
        Operator op;

        Arg arg1;
        ArgType type1;

        Arg arg2;
        ArgType type2;

        Symbol *result;

    public:
        QuadAsign(Operator op, Arg a1, ArgType t1, 
                  Arg a2, ArgType t2, Symbol *s) {

            this->op = op;
            this->arg1 = a1;
            this->type1 = t1;
            this->arg2 = a2;
            this->type2 = t2;
            this->result = s;
        }

        std::string emit() {
            std::string str = this->result->getId(); 
            str += " := ";    

            str += get_arg_string(this->arg1, this->type1);  //arg1
            str += get_op_string(this->op);                  //op
            str += get_arg_string(this->arg2, this->type2);  //arg2
            return str;
        }
};



#endif
