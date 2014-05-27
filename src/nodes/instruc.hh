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



#ifndef INSTRUC_HH
#define INSTRUC_HH 

class Instruc {
    private:
        int line, col;
    public:
        int get_line();
        int get_col();
        void set_line(int);
        void set_col(int);

        virtual bool check() = 0;
};

#endif
