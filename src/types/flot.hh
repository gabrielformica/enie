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
  * Class definitions for floating point type
  */


#include <string>

class Flot {
    private:
        float val;
    public:
        explicit Flot(float v) : val(v) { }
        float get();
        void set(float v);
        std::string check();

        /* Overloading operators */
        bool operator<(Flot n) { return (this->val < n.val); }
        bool operator>(Flot n) { return (this->val > n.val); }
        bool operator<=(Flot n) { return (this->val <= n.val); }
        bool operator>=(Flot n) { return (this->val >= n.val); }
        bool operator==(Flot n) { return (this->val == n.val); }

};
