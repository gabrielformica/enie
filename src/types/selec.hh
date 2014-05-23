/**
  * Copyright 2014
  *
  * @file selec.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for selection instruction type
  *
  */

#ifndef SELEC_HH
#define SELEC_HH

class Selec : public Instruc {
    private:
        Symbol *sym;
        Exp *expr;
    public:
        typedef Instruc super;

        explicit Selec(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* get_symbol();
        Exp* get_expression();
        void set_symbol(Symbol *s);
        void set_expression(Exp *e);
        bool check();
};

#endif
