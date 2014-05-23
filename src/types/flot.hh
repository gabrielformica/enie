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


#ifndef FLOT_HH
#define FLOT_HH

#include <string>
#include "exp.hh"

class Flot: public Exp {
    private:
        float val;
    public:
        explicit Flot(float v) : val(v) { }
        float get();
        void set(float v);

        /** Exp methods */
        string check() { return "flot"; }
        int offset() { return 64; }  //64 byte

        /* Overloading operators */
        bool operator<(Flot n) { return (this->val < n.val); }
        bool operator>(Flot n) { return (this->val > n.val); }
        bool operator<=(Flot n) { return (this->val <= n.val); }
        bool operator>=(Flot n) { return (this->val >= n.val); }
        bool operator==(Flot n) { return (this->val == n.val); }

        Flot operator+(Flot n) { return Flot(this->val + n.val); }
        Flot operator-(Flot n) { return Flot(this->val - n.val); }
        Flot operator*(Flot n) { return Flot(this->val * n.val); }
        Flot operator/(Flot n) { return Flot(this->val / n.val); }
        Flot operator%(Flot n) { return Flot(this->val % n.val); }



};

#endif
