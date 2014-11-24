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
  * MIPS Instruction class definition
  */

#ifndef MIPS_INST_HH
#define MIPS_INST_HH

#include <string>

class MipsInst {

    public:
        virtual std::string toString() = 0;
};

///////////////////////////////////Arithmetic///////////////////////////////////

class Add: public MipsInst {
    private:
        std::string res;
        std::string arg1;
        std::string arg2;

    public:
        Add(std::string z, std::string x, std::string y);

        void setArg1(std::string);
        void setArg2(std::string);
        void setRes (std::string);
        std::string toString();
};

class AddI: public MipsInst {
    private:
        std::string res;
        std::string arg1;
        int arg2; // this is an imm

    public:
        AddI(std::string z, std::string x, int i);

        void setArg1(std::string);
        void setArg2(int);
        void setRes(std::string);

        std::string toString();
};

class Sub: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string res;

    public:
        Sub(std::string z, std::string x, std::string y);

        void setArg1(std::string);
        void setArg2(std::string);
        void setRes(std::string);
        std::string toString();
};

class Mult: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
    public:
        Mult(std::string x, std::string y);
        std::string toString();
};


class Div: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
    public:
        Div(std::string x, std::string y);
        std::string toString();
};

/////////////////////////////////////Moves/////////////////////////////////////

class Mfhi: public MipsInst {
    private:
        std::string arg1;
    public:
        Mfhi(std::string x);
        std::string toString();
};

class Mflo: public MipsInst {
    private:
        std::string arg1;
    public:
        Mflo(std::string x);
        std::string toString();
};

class Move: public MipsInst {
    private:
        std::string arg1;
        std::string res;
    public:
        Move(std::string a1, std::string r);
        std::string toString();
};

/////////////////////////////////////Jumps/////////////////////////////////////

// This works for jump and jump and link?
// Don't know #checklater
class Jump: public MipsInst {
    private:
        std::string label;
    public:
        Jump(std::string l);
        std::string toString();
};

class Beq: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Beq(std::string a1, std::string a2, std::string l);
        std::string toString();
};

class Bne: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Bne(std::string a1, std::string a2, std::string l);
        std::string toString();
};

class Bge: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Bge(std::string a1, std::string a2, std::string l);
        std::string toString();
};

class Bgt: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Bgt(std::string a1, std::string a2, std::string l);
        std::string toString();
};

class Ble: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Ble(std::string a1, std::string a2, std::string l);
        std::string toString();
};


class Blt: public MipsInst {
    private:
        std::string arg1;
        std::string arg2;
        std::string label;
    public:
        Blt(std::string a1, std::string a2, std::string l);
        std::string toString();
};


/////////////////////////////////////Other/////////////////////////////////////

class Syscall: public MipsInst {
    public:
        Syscall();
        std::string toString();
};

#endif
