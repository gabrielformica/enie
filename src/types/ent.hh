/**
  * Copyright 2014
  *
  * @file ent.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for integer type
  *
  */

class Ent {
    private:
        int val;
    public:
        explicit Ent(int v) : val(v) { }
        int get_ent();
        void set_ent(int v);
};
