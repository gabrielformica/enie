#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Gabriel Formica


#Enie generator script
import sys
import random
from random import randint
import symboltable

indentation = 2 
current_instbl = 0


num_of_variables = 100

MIN_FUNCTIONS = 1  #min amount of functions definitions 
MAX_FUNCTIONS = 4 #max amount of functions definitions 
MIN_INSTBL = 5     #min amount of instructions in a block
MAX_INSTBL = 20    #max amount of instructions in a block

data_types = ['ent','bool','nada','flot','cad','car']
words = []                    
expressions = []
used_id = []

class program:
    def __init__(self):
        self.functionslist = []
        self.random_generation();

    def __str__(self):
        str0 = ""
        for f in self.functionslist:
            str0 = str0 + str(f) + "\n"
        return str0

    def random_generation(self):
        x = randint(MIN_FUNCTIONS,MAX_FUNCTIONS)
        for i in range(1,x+1):
            self.functionslist.append(function())



class varname:
    def __init__(self):
        self.var = None 

        self.random_generation()

    def __str__(self):
        return str(self.var)

    def random_generation(self):
        word = random.choice(words)
        word = word.replace("\n","")
        word = word.replace("'","")
        self.var = word
        #var names are differents of data types
        while self.var in data_types:
            self.var = varname()


class number:
    def __init__(self):
        self.value = None 

        self.random_generation()

    def __str__(self):
        return str(self.value)

    def random_generation(self):
        self.value = randint(-500,500)


class function:
    def __init__(self):
        self.name = None
        self.instbl = None 
        self.rtype = None 
        self.arglist = [] 

        self.random_generation()


    def __str__(self):
        str0 = str(self.name) + " :: " + str(self.arglist) + " -> "
        str0 = str0 + str(self.rtype) + " " + str(self.instbl)
        return str0

    def random_generation(self):
        self.name = varname()
        self.arglist = arglist()
        self.instbl = instbl()
        self.rtype = random.choice(data_types)



class arglist:
    def __init__(self):
        self.argl = []

        self.random_generation()

    def __str__(self):
        if not self.argl:
            return " ~ "

        str0 = ""
        for arg in self.argl:
            str0 = str0 + str(arg) + ", "
        return str0[:-2]      #all str0 except last ","

    def random_generation(self):
        x = randint(0,7)        #number of arguments
        for i in (0,x):
            self.argl.append(decl())



class instbl:
    def __init__(self):
        self.instlist = []

        self.random_generation()

    def __str__(self):
        return "{\n" + str(self.instlist) + "}"

    def random_generation(self):
        self.instlist =  instlist()



class instlist:
    def __init__(self):
        self.instl = []

        self.random_generation()

    def __str__(self):
        str0 = ""
        for inst in self.instl:
            str0 = str0 + str(inst) + "\n"
        return str0

    def random_generation(self):
        x = randint(MIN_INSTBL,MAX_INSTBL) #number of instructions
        for i in range(0,x):
            self.instl.append(instruction())


class instruction:
    def __init__(self):
        self.inst = None

        self.random_generation()

    def __str__(self):
        spaces = " "*indentation
        return spaces + str(self.inst)

    def random_generation(self):
        inst_set = [
                    assign(), functioncall(),
                    decl(), declassign(),
                    #detite(), indite(),
                    #case(), 
                    ]

        self.inst = random.choice(inst_set)



class assign:
    def __init__(self):
        self.var = None 
        self.exp = None 

        self.random_generation()

    def __str__(self):
        return str(self.var) + " = " + str(self.exp)

    def get_var(self):
        return str(self.var)

    def random_generation(self):
        exps = [arithexp(), booleanexp()]
        self.var = varname()
        self.exp = random.choice(exps)


class functioncall:
    def __init__(self):
        self.explist = []

        self.random_generation()

    def __str__(self):
        return str(self.name) + "(" + str(self.explist) + ")"

    def random_generation(self):
        self.name = varname()
        self.explist = explist()

class decl:
    def __init__(self):
        self.datatype = None 
        self.var = None 

        self.random_generation()

    def __str__(self):
        return str(self.datatype) + " " + str(self.var)

    def random_generation(self):
        self.datatype = random.choice(data_types)
        self.var = varname()



class declassign(decl):
    def __init__(self):
        self.datatype = None 
        self.var = None 
        self.exp = None 

        self.random_generation()
 
    def __str__(self):
        return str(self.datatype) + " " + str(self.var) + " = " + str(self.exp)

    def random_generation(self):
        self.datatype = random.choice(data_types)
        self.var = varname()
        l = [booleanexp(), arithexp()]
        self.exp = random.choice(l) 



class exp:
    def __init__(self):
        self.left = None 
        self.ope = None
        self.right = None 
        self.opelist = []

    def __str__(self):
        return "(" + str(self.left) + " " + str(self.ope) + " " + str(self.right) + ")"

   
class explist:
    def __init__(self):
        self.l = []
        
        self.random_generation()
        
    def __str__(self):
        str0 = ""
        for exp in self.l:
            str0 = str0 + str(exp) + ","
        
        return str0[:-1]

    def random_generation(self):
        x = randint(1,5)
        for i in range(0,x):
            self.l.append(varname())


class booleanexp(exp):
    def __init__(self):
        exp.__init__(self)

        self.opelist = ['<','<=','>','>=','==','!=', '&&', '||']

        self.random_generation()

    def random_generation(self):
        #list of posibles expressions in a boolean expression
        explist1 = [number(), varname()]
        explist2 = [number(), varname()]

        self.left = random.choice(explist1)
        self.ope = random.choice(self.opelist)

        self.right = random.choice(explist2)
         


        
class arithexp(exp):
    def __init__(self):
        exp.__init__(self)

        self.opelist = ['+','-','/','*','%','^']

        self.random_generation()

    def random_generation(self):
        explist1 = [number(), varname()]
        explist2 = [number(), varname()]

        self.left = random.choice(explist1)
        self.ope = random.choice(self.opelist)
        self.right = random.choice(explist2)



class detite:
    def __init__(self):
        self.init = None 
        self.cond = None
        self.incr = None 
        self.instbl = None 

        self.random_generation()

    def __str__(self):
        str0 = "para (" + self.decl + "; "+ self.cond + "; " + self.incr+ ")"
        str0 = str0 + str(self.instbl)
        return str0 

    def random_generation(self):
        self.init = declassign()
        self.cond = booleanexp()
        self.incr = arithexp()
        self.instbl = instbl()



class indite:
    def __init__(self):
        self.cond = cond
        self.instbl = instbl

        self.random_generation()

    def __str__(self):
        return  "mientras (" + str(self.cond) + ") " + str(self.instbl)

    def random_generation(self):
        self.cond = booleanexp()
        self.instbl = instbl()



class case:
    def __init__(self):
        self.var = None 
        self.optionslist = []

        self.random_generation()

    def __str__(self):
        return "caso "+ str(self.var) + " {\n" + str(self.optionslist) + "}"

    def random_generation(self):
        self.var = varname()
        self.optionslist = optionslist()

class optionslist:
    def __init__(self):
        self.opts = []

        self.random_generation()

    def __str__(self):
        str0 = ""
        spaces = " "*(indentation*2)
        for opt in self.opts:
            str0 = spaces + str0 + str(opt) + "\n" 
        return str0

    def random_generation(self):
        x = randint(1,10)  #number of cases
        for i in range(1,x): 
            self.opts.append(option())


class option:
    def __init__(self):
        self.case = None 
        self.instbl = None

        self.random_generation()
    def __str__(self):
        return str(self.case) + " -> " + str(self.instbl)

    def random_generation(self):
        self.case = varname()
        self.instbl = instbl()

    
#Initalize basic data structures
def initialize():
    global words
    words_file = open('/etc/dictionaries-common/words','r')
    words = words_file.readlines()
    words_file.close()
    random.shuffle(words)
    words = words[:100]

    

def instructions():
    
    token = get_random_id()


def main():
    initialize()

    print str(program())
    
if __name__ == "__main__":
    main()
