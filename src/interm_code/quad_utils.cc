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


#include <string>
#include "quad_utils.hh"

std::string get_arg_string(Arg arg, ArgType type) {
        std::string str = "";
        switch (type) {
                Var:    
                    str += (arg).var->getId();  //It's a symbol
                    break;
                ConstEntero: 
                    str += std::to_string(arg.const_ent);  
                    break;
                ConstFlotante:
                    str += std::to_string(arg.const_flot);  
                    break;
                ConstBooleana: 
                    if (arg.const_boolean) 
                        str += "cierto";
                    else
                        str += "falso";
                    break;
                ConstCar:
                    str += arg.const_car;
                    break;
                ConstCadena:
                    str += *(arg.const_cad);
                    break;
                default:
                    break;
            }

        return str;
};


/**
  * Returns the string of an operator
  */

std::string get_op_string(Operator op) {
    std::string str = "";
    switch (op) {
        Pot:    
            str += " ^ ";
            break;
        Mult: 
            str += " * ";
            break;
        Divi:
            str += " / ";
            break;
        Suma: 
            str += " + ";
            break;
        Resta:
            str += " - ";
            break;
        Mod:
            str += " % ";
            break;
        Men:
            str += " < ";
            break;
        Meni:
            str += " <= ";
            break;
        May:
            str += " > ";
            break;
        Mayi:
            str += " >= ";
            break;
        Equiv:
            str += " == ";
            break;
        Dif:
            str += " != ";
            break;
        Y:
            str += " & ";
            break;
        O:
            str += " | ";
            break;
        No:
            return  " ! ";
        default:
            break;
    }

    return str;

};


