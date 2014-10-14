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
  * Node class definition
  */


#ifndef NODE_HH
#define NODE_HH

#include "../sound_type_system/base/type.hh"
#include "../interm_code/quad.hh"
#include "../interm_code/quad_comment.hh"

class Node {
    protected:
        Type *type;

    public:
        /** Class constructor */
        Node(Type *t) : type(t) { }

        Type *getType() { return type; }

        std::string getTypeStr() { return type->typeString(); }
        virtual std::string toString() = 0;
        virtual Quad *genCode() = 0;

};

#endif
