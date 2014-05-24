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
        int value;
    public:
        explicit Ent(int v) : value(v) { }
        int getValue();
        void setValue(int v);

        /** Exp methods */
        std::string getType() { return "ent"; };
        int offset() { return 32; };  //32 byte
        
        /* Overloading operators */
        bool operator<(Ent n) { return (this->value < n.value); }
        bool operator>(Ent n) { return (this->value > n.value); }
        bool operator<=(Ent n) { return (this->value <= n.value); }
        bool operator>=(Ent n) { return (this->value >= n.value); }
        bool operator==(Ent n) { return (this->value == n.value); }

        Ent operator+(Ent n) { return Ent(this->value + n.value); }
        Ent operator-(Ent n) { return Ent(this->value - n.value); }
        Ent operator*(Ent n) { return Ent(this->value * n.value); }
        Ent operator/(Ent n) { return Ent(this->value / n.value); }
        Ent operator%(Ent n) { return Ent(this->value % n.value); }
};

#endif
