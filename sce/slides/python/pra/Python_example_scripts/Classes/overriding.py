#!/usr/bin/python 


# simple example of method overriding through inheritance 


class parent: 

	def func(self):
		print "This is parent's func() " 


class child(parent): 

	def func(self): 				# overridden 
		print "This is child's func()"


p=parent() 

c=child() 

p.func() 

c.func() 



