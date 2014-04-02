#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Gabriel Formica


#Enie generator script
import sys
import random
from random import randint
import symboltable

num_of_variables = 100

MIN_INSTBL = 5    #min amount of instructions in a block
MAX_INSTBL = 15   #max amount of instructions in a block

data_types = ['ent','bool','nada','flot','cad','car']
words = []                    
expressions = []
used_id = []


class function:
    def __init__(self,name=None,arglist=None,instbl=None,rtype=None):
        self.name = name
        self.arglist = arglist
        self.instbl = instbl
        self.rtype = rtype

    def __str__():
        str0 = str(self.name) + " :: " + str(arglist) + " -> "
        str0 = str0 + str(rtype) + str(self.instbl)
        return str0

    def random_generation(self):
        self.name = name().random_generation()
        self.arglist = arglist().random_generation()
        self.instbl = instbl().random_generation()
        self.rtype = datatype().random_generation()



class arglist:
    def __init__(self):
        self.argl = []

    def __str__():
        if not self.argl:
            return " ~ "
        for arg in self.argl:
            str0 = str0 + str(arg) + ","
        return str0[:-1]      #all str0 except last ","

    def random_generation(self):
        x = randint(0,7)        #number of arguments
        for i in (0,x):
            self.argl.append(decl().random_generation())


       

class instbl:
    def __init__(self,instlist=None):
        self.instlist = instlist

    def __str__():
        return "{\n" + str(self.instlist) + "\n}"

    def random_generation(self):
        self.instlist =  instlist().random_generation()


class instlist:
    def __init__(self):
        self.instl = []

    def __str__():
        str0 = ""
        for inst in self.instl:
            str0 = str0 + str(inst) + "\n"
        return str0

    def random_generation(self):
        x = randint(MIN_INSTBL,MAX_INSTBL) #number of instructions
        for i in range(0,x):
            self.instl.append(instruction().random_generation())


class instruction:
    def __init__(self):
        self.inst = None

    def __str__():
        return str(self.inst)

    def random_generation(self):
        inst_set = [
                    assign(), functioncall(),
                    decl(), declassign(),
                    detite(), indite(),
                    case() 
                    ]

        inst_object = random.choice(inst_set)
        self.inst = inst_object.random_generation()



class assign:
    def __init__(self,var,exp):
        self.var = var
        self.exp = exp 

    def __str__(self):
        return str(self.var) + " = " + str(self.exp)



class decl:
    def __init__(self,datatype=None,var=None):
        self.datatype = datatype
        self.var = var

    def __str__():
        return str(self.type) + " " + str(self.var)

    def random_generation(self):
        self.datatype = random.choice(data_types)

        #var names are differents of data types
        self.var = random.choice(words)
        while self.var in data_types:
            self.var = random.choice(words) 

class declassign(decl):
    def __init__(self,datatype=None,var=None,exp=None):
        self.datatype = datatype
        self.var = var
        self.exp = exp

    def __str__():
        return str(self.datatype) + " " + str(self.var) + " = " + str(self.exp)

    def random_generation(self):
        decl_object = decl().random_generation()
        self.datatype = decl_object

 


class exp:
    def __init__(self,left,ope,right):
        self.left = left
        self.ope = ope
        self.right
    
    def __str__():
        return str(self.left) + str(selfope) + str(self.right)
        

class detite:
    def __init__(self,init,cond,incr,instbl):
        self.init = init 
        self.cond = cond
        self.incr = incr 
        self.instbl = instbl

    def __str__():
        str0 = "para (" + self.decl + "; "+ self.cond + "; " + self.incr+ ")"
        str0 = str0 + str(self.instbl)
        return str0 


class indite:
    def __init__(self,cond,instbl):
        self.cond = cond
        self.instbl = instbl

    def __str__():
        return  "mientras (" + str(self.cond) + ") " + str(self.instbl)


class case:
    def __init__(self,var,optionslist):
        self.var = var
        self.optionslist = optionslist

    def __str__():
        return "caso "+ str(self.var) + "{\n" + str(self.optionslist) + "\n}"


class optionslist:
    def __init__(self):
        self.opts = []

    def __str__():
        str0 = ""
        for opt in self.optlist:
            str0 = str0 + str(opt) + "\n" 
        return str0


class option:
    def __init__(self,case, instbl):
        self.case = case
        self.instbl = instbl

    def __str__():
        return str(self.case) + " -> " + str(self.instbl)

    
#Initalize basic data structures
def initialize():
    words_file = open('/etc/dictionaries-common/words','r')
    random_words = words_file.readlines()
    words_file.close()
    random.suffle(random_words)
    loadvariables(random_words)
    

def instructions():
    
    token = get_random_id()


def main():
    exp1 = exp("3+4","-","2*2")
    inst1 = assgin("a",exp1)
    mient1 = indite("("+exp1+")",instbl1)
    initialize()
    
if __name__ == "__main__":
    main()
