#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Gabriel Formica 

#Symbol table class
class symboltable:

    def __init__(self):
        self.table = {}

    def insert(self,key,value):
        self.table[key] = value

    def delete(self,elem):
        if self.table.is_member(elem):
            del self.table[str(elem)]

    def update(self,elem,value):
        if self.is_member(elem):
            self.table[str(elem)] = value

    def is_member(self,key):
        if key in self.table:
            return True
        return False
    
    def is_empty(self):
        return len(self.table.keys()) == 0

