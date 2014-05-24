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
        float value;

    public:
        explicit Flot(float v) : value(v) { }
        float getValue();
        void setValue(float v);

        /** Exp methods */
        std::string getType() { return "flot"; }
        int offset() { return 64; }  //64 byte

        /* Overloading operators */
        bool operator<(Flot n) { return (this->value < n.value); }
        bool operator>(Flot n) { return (this->value > n.value); }
        bool operator<=(Flot n) { return (this->value <= n.value); }
        bool operator>=(Flot n) { return (this->value >= n.value); }
        bool operator==(Flot n) { return (this->value == n.value); }

        Flot operator+(Flot n) { return Flot(this->value + n.value); }
        Flot operator-(Flot n) { return Flot(this->value - n.value); }
        Flot operator*(Flot n) { return Flot(this->value * n.value); }
        Flot operator/(Flot n) { return Flot(this->value / n.value); }
};

#endif
