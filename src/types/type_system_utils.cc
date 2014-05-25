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
  * Type System function implementation 
  */


#include "type_system_utils.hh"
#include <string>
#include <iostream>
#include "exp.hh"
#include "expbin.hh"
#include "ent.hh"
#include "flot.hh"
#include "type_error.hh"


/**
  * Returns the binary expression 
  * @param e1     : left expression
  * @param e2     : right expression
  * @param ope    : operator
  * @param line   : line of the binary expression
  * @param column : column of the binary expression
  *
  * @return A ExpBin, if it's valid. TypeError Exp if it's not
  */

Exp *get_expbin(Exp *e1, Exp *e2, std::string ope, int line, int column) {
    if (check_expbin(e1, e2, ope)) {
       Exp *exp = new ExpBin(e1, e2);
       return exp;
    }

    Exp *exp = new ExpBin(e1, e2, "error"); 
    Exp *error = new TypeError(exp, line, column);
    return error;
}


/**
  * Returns the type of a binary expression
  * @param e1  : pointer to first expression
  * @param e2  : pointer to second expression
  * @param ope : string operand
  */


bool check_expbin(Exp *e1, Exp *e2, std::string ope) {
    std::string t1 =  e1->getType();
    std::string t2 =  e2->getType();

    if (t1 != t2)
        return false;

    if ((t1 == "ent") && (is_arithmetic_ent(ope) || is_relational(ope)))
        return true;

    if ((t1 == "flot") && (is_arithmetic_flot(ope) || is_relational(ope)))
        return true;

    if ((t1 == "bool") && (is_boolean(ope)))
        return true;


    return false;
}


/**
  * Tells if an operator is an arithmetic operator
  * @param o : operator
  * @return True, if o is an aritmetic operator. False in any other case
  */

bool is_arithmetic_ent(std::string o) {
    return ((o == "+") || (o == "-") || (o == "/") ||
            (o == "*") || (o == "%") || (o == "^") );
}


/**
  * Tells if an operator is an arithmetic operator
  * @param o : operator
  * @return True, if o is an aritmetic operator. False in any other case
  */

bool is_arithmetic_flot(std::string o) {
    return ((o == "+") || (o == "-") || (o == "/") || (o == "*"));
}


/**
  * Tells if an operator is boolean operator 
  * @param o : operator
  * @return True, if o is an boolean operator. False in any other case
  */

bool is_boolean(std::string o) {
    return ((o == "||") || (o == "&&") || (o == "!"));
}


/**
  * Tells if an operator is a relational operator 
  * @param o : operator
  * @return True, if o is a relational operator. False in any other case
  */

bool is_relational(std::string o) {
    return ((o == "==") || (o == "!=") ||
            (o == "<")  || (o == "<=") || (o == ">") || (o == ">="));
}

