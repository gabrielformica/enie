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


#include <string>
#include <iostream>
#include "type_system_utils.hh"
#include "base/type.hh"
#include "base/ent.hh"
#include "base/flot.hh"
#include "../nodes/node.hh"
#include "../nodes/exp.hh"
#include "../nodes/expbin.hh"
#include "base/type_error.hh"




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

Exp *get_expbin(Exp *e1, Exp *e2, std::string ope) {
    if (check_expbin(e1, e2, ope)) {
        Exp *exp = new ExpBin(e1, e2, e1->getType());
        return exp;
    }

    if (e1->getTypeStr() == "error")
        return e1;

    if (e2->getTypeStr() == "error")
        return e2;

    return NULL;
}


/**
  * Returns the type of a binary expression
  * @param e1  : pointer to first expression
  * @param e2  : pointer to second expression
  * @param ope : string operand
  */


bool check_expbin(Exp *e1, Exp *e2, std::string ope) {
    std::string t1 =  e1->getTypeStr();
    std::string t2 =  e2->getTypeStr();

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
    return ((o == "|") || (o == "&") || (o == "!"));
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

