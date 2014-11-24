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
  * Class definitions for arguments 
  */


#ifndef ARGUMENTS_HH
#define ARGUMENTS_HH

#include "../symtable/symbol.hh"
#include "../sound_type_system/base/type.hh"

class Argument {
    protected:
        Type *type;
    public:
        Type *getType();
        virtual bool is(std::string) = 0;
        virtual std::string toString() = 0;

};

class ArgumentVar: public Argument {
    protected:
        Symbol *var;
    public:
        ArgumentVar(Symbol *var, Type *t); 
        bool is(std::string);
        std::string toString();
        Symbol *getSymbol();

};

class ArgumentConst: public Argument {
    protected:
        std::string elem;
    public:
        ArgumentConst(std::string elem, Type *t); 
        bool is(std::string);
        std::string toString();

};



#endif
