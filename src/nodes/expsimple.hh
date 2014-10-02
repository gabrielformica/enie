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
  * Class definitions for simple expressions
  */


#ifndef EXPSIMPLE_HH
#define EXPSIMPLE_HH

class ExpSimple: public Exp {
    protected:
        std::string elem;

    public:
        typedef Exp super;

        /** Class constructor */
        ExpSimple(std::string elem, Type *t) : super(t) {
            this->elem = elem;
            this->op = NULL;
        }

        ExpSimple(Type *t) : super(t) {
            this->elem = "";
        }

        std::string getElem() { return this->elem; }

        std::string toString() {
            return "Expresion : \n" + this->opToString() + this->elem;
        }


};

#endif
