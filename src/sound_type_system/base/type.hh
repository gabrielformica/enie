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
        int bytes = 0;   //Number of bytes of the type

    public:
        Type(int b) : bytes(b) { }

        virtual std::string typeString() = 0 ;
        virtual bool  is(std::string) = 0;
        void setBytes() { }
        int getBytes() { return this->bytes; }
};

#endif
