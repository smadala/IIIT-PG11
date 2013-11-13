#!/usr/bin/python 

# simple demo of creating subclasses in Python 


class parent: 

	def parentmethod(self):
		print 'Inside parent method' 

class child(parent): 

	def childmethod(self):
		print 'Inside child method' 


p=parent()		# instance of 'parent' class

c=child()               # instance of 'child' class

p.parentmethod() 

c.childmethod()

#p.childmethod() 	# ??? 

#c.parentmethod()       # ??? 
