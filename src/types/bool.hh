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
  * Class definitions for boolean type
  */


#include <string>

class Bool {
    private:
        bool val;
    public:
        explicit Bool(bool v) : val(v) { }
        int get();
        void set(bool v);
        std::string check();
};
