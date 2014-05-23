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


#ifndef ENT_HH
#define ENT_HH

#include <string>
#include "exp.hh"

class Ent: public Exp {
    private:
        int val;
    public:
        explicit Ent(int v) : val(v) { }
        int get();
        void set(int v);

        /** Exp methods */
        std::string check() { return "ent"; };
        int offset() { return 32; };  //32 byte
        
        /* Overloading operators */
        bool operator<(Ent n) { return (this->val < n.val); }
        bool operator>(Ent n) { return (this->val > n.val); }
        bool operator<=(Ent n) { return (this->val <= n.val); }
        bool operator>=(Ent n) { return (this->val >= n.val); }
        bool operator==(Ent n) { return (this->val == n.val); }

        Ent operator+(Ent n) { return Ent(this->val + n.val); }
        Ent operator-(Ent n) { return Ent(this->val - n.val); }
        Ent operator*(Ent n) { return Ent(this->val * n.val); }
        Ent operator/(Ent n) { return Ent(this->val / n.val); }
        Ent operator%(Ent n) { return Ent(this->val % n.val); }
};

#endif
