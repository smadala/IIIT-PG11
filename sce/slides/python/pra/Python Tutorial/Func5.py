#!/usr/bin/python

# Scope of variables: local and global
name = "SCE"

def f():
   name = "Scripting"
   print "Inside function: ", name

def g():
   global name 					# use global keyword to change global variables inside the function
   name = "Scripting"
   print "Inside function: ", name

print "Before Local Function Call: ", name
f()
print "After Local Function Call: ", name

g()
print "After Global Function Call:", name

