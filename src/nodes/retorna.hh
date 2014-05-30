/**
  * Copyright 2014
  *
  * @file retorno.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for return instruction
  *
  */

#ifndef RETORNA_HH 
#define RETORNA_HH

class Retorna: public Instruc {
    private:
        Exp *exp;

    public:

        typedef Instruc super;
        Retorna(Exp *exp) : super(NULL) {
            this->exp = exp;
        }

        Retorna() : super(NULL) {
            this->exp = NULL;
        }

};

#endif

