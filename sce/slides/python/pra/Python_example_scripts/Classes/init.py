#!/usr/bin/python 

# demo of class instantiation using the __init__ special method 

# we do not explicitly call the __init__ method but pass the arguments in the parentheses following the class name 
# when creating a new instance of the class.

#global name="Alice"

class person:
      
     def __init__(self, who):      # default constructor 
          self.name = who 	   # notice the use of the 'self' keyword

     def display(self):           
          print 'Hello', self.name

I1=person('Alice')                # first instance 

I2=person('Bob')		# another instance 
#person('Bob').display()	# alternative syntax


print I1.name			# access the attribute

print I2.name 

I1.display()                      # access the method 

I2.display() 

