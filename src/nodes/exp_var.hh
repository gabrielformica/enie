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
  * Class definitions for simple expressions that are a variable
  */

#ifndef EXP_VAR_HH
#define EXP_VAR_HH

#include "../symtable/symbol.hh"

class ExpVar: public ExpSimple {
    protected:
        Symbol *var;
    public:
        typedef ExpSimple super;

        /** Class constructor */
        ExpVar(Type *t) : super(t) { this->var = NULL; };

        ExpVar(Symbol *s, Type *t) : super(s->getId(), t) {
            this->var = s;
        }

        bool is(std::string str) { return "ExpVar" == str; }

        Symbol *getVar() { return this->var; }

        Quad *genCode() {
            Symbol *temp = get_next_temp();
            Argument *result = new ArgumentVar(temp, this->type);
            Argument *arg1 = new ArgumentVar(this->var, this->type);

            Quad *q1 = new Quad(":=", arg1, NULL, result);
            gen_un_op(q1, this->op);
            return q1;
        }
};

#endif
