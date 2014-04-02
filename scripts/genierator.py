#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Gabriel Formica


#Enie generator script
import sys
import random
from random import randint
import symboltable

num_of_variables = 100

MIN_FUNCTIONS = 4  #min amount of functions definitions 
MAX_FUNCTIONS = 10 #max amount of functions definitions 
MIN_INSTBL = 5     #min amount of instructions in a block
MAX_INSTBL = 15    #max amount of instructions in a block

data_types = ['ent','bool','nada','flot','cad','car']
words = []                    
expressions = []
used_id = []

class program:
    def __init__(self,functionslist=None):
        self.functionslist = functionslist

    def __str__():
        str0 = ""
        for f in functionslist:
            str0 = str0 + str(f) + "\n"
        return str0

    def random_generation(self):
        x = randint(MIN_FUNCTIONS,MAX_FUNCTIONS)
        for i in range(1,x):
            self.functionslist.append(function().random_generation())




class varname:
    def __init__(self,var=None):
        self.var = var
    def __str__():
        return str(self.var)
    def random_generation():
        self.var = varname().random_generation()



class number:
    def __init__(self,value=None):
        self.value = value

    def __str__():
        return str(self.value)

    def random_generation():
        self.value = randint(-500,500)



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
    def __init__(self,argl=None):
        self.argl = argl 

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
    def __init__(self,instl=None):
        self.instl = instl 

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

    def get_var(self):
        return str(self.var)



class decl:
    def __init__(self,datatype=None,var=None):
        self.datatype = datatype
        self.var = var

    def __str__():
        return str(self.type) + " " + str(self.var)

    def get_var():
        return str(self.var)

    def random_generation(self):
        self.datatype = random.choice(data_types)

        #var names are differents of data types
        self.var = varname().random_generation() 
        while self.var in data_types:
            self.var = varname().random_generation()



class declassign(decl):
    def __init__(self,datatype=None,var=None,exp=None):
        decl.__init__(self,datatype,var)
        self.exp = exp

    def __str__():
        return str(self.datatype) + " " + str(self.var) + " = " + str(self.exp)

    def random_generation(self):
        decl_object = decl().random_generation()
        self.datatype = decl_object.get_datatype()
        self.var = decl_object.get_var()
        self.exp = exp().random_generation()



class exp:
    def __init__(self,left,ope,right):
        self.left = left
        self.ope = ope
        self.right = right
        self.opelist = []
    
    def __str__():
        return str(self.left) + str(selfope) + str(self.right)

   


class booleanexp(exp):
    def __init__(self,left=None,ope=None,right=None):
        exp.__init__(self,left,ope,right)
        self.opelist = ['<','<=','>','>=','==','!=', '&&', '||']

    def random_generation(self):
        #list of posibles expressions in a boolean expression
        explist = [number(),varname(),booleanexp(),varname(),number(),arithexp()]
        self.left = random.choice(self.explist).random_generation()
        self.ope = random.choice(self.opelist)
        self.right = random.choice(self.explist).random_generation()
         


        
class arithexp(exp):
    def __init__(self,left=None,ope=None,right=None):
        exp.__init__(self,left,ope,right)
        self.opelist = ['+','-','/','*','%','^']

    def random_generation(self):
        explist = [number(),varname(),varname(),number(),arithexp()]
        self.left = random.choice(self.explist).random_generation()
        self.ope = random.choice(self.opelist)
        self.right = random.choice(self.explist).random_generation()



class detite:
    def __init__(self,init=None,cond=None,incr=None,instbl=None):
        self.init = init 
        self.cond = cond
        self.incr = incr 
        self.instbl = instbl

    def __str__():
        str0 = "para (" + self.decl + "; "+ self.cond + "; " + self.incr+ ")"
        str0 = str0 + str(self.instbl)
        return str0 

    def random_generation(self):

        self.init = declassign().random_generation()
        self.cond = booleanexp().random_generation()
        self.incr = arithexp().random_generation()
        self.instbl = instbl().random_generation()



class indite:
    def __init__(self,cond,instbl):
        self.cond = cond
        self.instbl = instbl

    def __str__():
        return  "mientras (" + str(self.cond) + ") " + str(self.instbl)

    def random_generation(self):
        self.cond = booleanexp().random_generation()
        self.instbl = instbl().random_generation()



class case:
    def __init__(self,var,optionslist):
        self.var = var
        self.optionslist = optionslist

    def __str__():
        return "caso "+ str(self.var) + "{\n" + str(self.optionslist) + "\n}"

    def random_generation(self):
        self.var = varname().random_generation()
        self.optionslist = optionslist().random_generation()

class optionslist:
    def __init__(self,opts=None):
        self.opts = opts 

    def __str__():
        str0 = ""
        for opt in self.optlist:
            str0 = str0 + str(opt) + "\n" 
        return str0

    def random_generation(self):
        x = randint(1,10)  #number of cases
        for i in range(1,x): 
            self.optionslist.append(option.random_generation())


class option:
    def __init__(self,case=None,instbl=None):
        self.case = case
        self.instbl = instbl

    def __str__():
        return str(self.case) + " -> " + str(self.instbl)

    def random_generation(self):
        self.case = varname().random_generation()

    
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
    print str(program().random_generation())
    
if __name__ == "__main__":
    main()
