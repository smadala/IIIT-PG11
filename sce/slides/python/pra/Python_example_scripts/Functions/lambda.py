#!/usr/bin/python

# Lambda expressions (a.k.a anonymous functions) too create a function object. 
#They are simpler than the usual functions defined by 'def'
# Lambda's body is a single expression, not a block of statments. 


#def f(a,b,c):		
#	return a+b+c


f=lambda a,b,c: a+b+c

print f(1,2,3)

print f('hi', 'aha', 'bye')



L=[lambda x: x**2,		# they can appear in 'unusual' places, say inside lists
   lambda x: x**4]

for f in L:
	print f(3)


