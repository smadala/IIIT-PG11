#!/usr/bin/python 
# demo of class methods and instances in Python 


class MyMath: 
	"""class method example """

	def add(self, x,y): 
		return x+y 

	def sub(self, x,y):
		return x-y 

	def mul(self, x,y):
		return x*y 

	def div(self,x,y):
		return x/y 

        def compute(self):
	    print self.add(2,4)			# calling the add() method of same class, thus 'self' needed
            print self.sub(2,4)
            print self.mul(2,4)
	    print self.div(2,4) 

I1=MyMath()     				# creating a class instance 

I1.compute()

#print I1.add(3,6)
#print I1.sub(3,6)
#print I1.mul(3,6)
#print I1.div(3,6)
#print '--------------'
 

