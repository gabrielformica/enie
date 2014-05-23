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

class Multselec : public Instruc {
    private:
        Symbol *sym;
        // Expression *expr;
    public:
        explicit Multselec(Symbol *s, Expression *e) : sym(s), exp(e) { }
        Symbol* get_symbol();
        // Expression* get_expression();
        void set_symbol(Symbol *s);
        // void set_expression(Expression *e);
        bool check();
};
