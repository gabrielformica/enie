/**
  * Copyright 2014
  *
  * @file multselec.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for case instruction type
  *
  */

#ifndef MULTSELEC_HH
#define MULTSELEC_HH

class Multselec : public Instruc {
    private:
        Symbol *sym;
        Exp *expr;
    public:
        explicit Multselec(Symbol *s, Exp *e) : sym(s), exp(e) { }

        Symbol* get_symbol();
        Exp* get_expression();
        void set_symbol(Symbol *s);
        void set_expression(Exp *e);
        bool check();
};

#endif
