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
  * Type class definition
  */


#ifndef TYPE_HH
#define TYPE_HH

class Type {
    protected:
        int bytes;   //Number of bytes of the type

    public:
        Type(int b) : bytes(b) { }
        
        virtual std::string typeString() = 0 ;

};

#endif
