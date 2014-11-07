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
  * Class definitions for simple expressions that are constant
  */


#ifndef EXP_CONST_HH
#define EXP_CONST_HH

class ExpConst: public ExpSimple {
    public:
        typedef ExpSimple super;

        /** Class constructor */
        ExpConst(Type *t) : super(t) { };

        ExpConst(std::string elem, Type *t) : super(elem, t) {};

        bool is(std::string str) { return str == "ExpConst"; }

        Quad *genCode() {
            Argument *arg = new ArgumentConst(this->elem, this->type);
            Quad *q = new Quad(":=", arg, NULL, arg);
            gen_un_op(q, this->op);
            return q;
        }


        Quad *genJumpingCode(std::string true_label, std::string false_label) {
            ArgumentConst *true_arg  = new ArgumentConst(true_label, NULL);
            ArgumentConst *false_arg = new ArgumentConst(false_label, NULL);

            Quad *q = NULL;
            if (this->op == "!") {
                q = new Quad("goto", false_arg, NULL, false_arg);
            } else {
                q  = new Quad("goto", true_arg, NULL, true_arg);
            }

            return q;
        }

};

#endif
