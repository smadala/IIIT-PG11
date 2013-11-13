#!/usr/bin/python


S='I am global' 

def f(): 

       S='I am Local' 
	
       print S 

f()                        # call f()

print S 
