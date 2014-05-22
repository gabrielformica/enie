/**
  * Copyright 2014
  *
  * @file flot.hh
  *
  *
  * @author: Gabriel Formica <gabrielformica93@gmail.com>
  * @author: Melecio Ponte <pontezambrano@gmail.com>
  *
  * @section Description
  *
  * Class definitions for floating point type
  *
  */

class Flot {
    private:
        float val;
    public:
        explicit Flot(float v);
        float get_flot();
        void set_flot(float v);
};
