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
  * Utils for Quads 
  */

#ifndef QUAD_UTILS_HH
#define QUAD_UTILS_HH

#include <string>

enum Operator {
    Pot,             //Power operator
    Mult,            //Multiplication operator
    Divi,            //Division operator
    Suma,            //Adition operator
    Resta,           //Substraction operator
    Mod,             //Modulus operator
    Men,             // < 
    Meni,            // <=
    May,             // >
    Mayi,            // >=
    Equiv,           // ==
    Dif,             // !=
    Y,               // &  (And operator)
    O,               // |  (Or operator)
    No               // !  (Not operator)
};

/**
  * Possible args in a Quad
  */

typedef union Arg Arg;

union Arg {
    Symbol *var;
    int const_ent;  
    float const_flot;
    bool const_boolean;
    char const_car; 
    std::string *const_cad;
};

enum ArgType {
    Var,
    ConstEntero,
    ConstFlotante,
    ConstBooleana,
    ConstCar,
    ConstCadena
};


/**
  * Returns the string of an arg, given the argument type
  */

std::string get_arg_string(Arg arg, ArgType type); 

/**
  * Returns the string of an operator
  */

std::string get_op_string(Operator op);

#endif
