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
  * Class definitions for cpu register type
  *
  */

#ifndef CPUREG_HH
#define CPUREG_HH

class CpuReg: public Type {
  public:
      typedef Type super;

      /** Class constructor */
      CpuReg() : super(4) { }

      std::string typeString() { return "cpureg"; }
      bool is(std::string t) { return t == "cpureg"; }
      void setWidth() { this->width = 4; }
};

  #endif
