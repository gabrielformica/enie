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
  * Class definitions for integer type
  */


#include <string>

class Ent {
    private:
        int val;
    public:
        explicit Ent(int v) : val(v) { }
        int get();
        void set(int v);
        std::string check();

        /* Overloading operators */
        bool operator<(Ent n) { return (this->val < n.val); }
        bool operator>(Ent n) { return (this->val > n.val); }
        bool operator<=(Ent n) { return (this->val <= n.val); }
        bool operator>=(Ent n) { return (this->val >= n.val); }
        bool operator==(Ent n) { return (this->val == n.val); }
};
