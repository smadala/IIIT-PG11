#!/usr/bin/python 

# another example of __init__ in action. 

class Counter:

	def __init__(self):				# default constructor 
		self.value = 0				# 'value' is class attribute 

	def increment(self):
		self.value += 1

	def show(self):
		print "Current value is %d" % self.value

	def reset(self):
		self.value=0 

c1 = Counter()			# new instance created 

c1.show()           # access the show() 


c1.increment()

c1.show() 

c1.increment()

c1.show() 

c1.reset() 

c1.show() 
