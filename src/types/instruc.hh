/**
  * Copyright 2014
  *
  * @file instruct.hh
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

class Instruc {
    private:
        int line, col;
    public:
        explicit Instruc() : { }
        virtual ~Instruc();

        int get_line();
        int get_col();
        void set_line();
        void set_col();

        virtual bool check() = 0;
};
