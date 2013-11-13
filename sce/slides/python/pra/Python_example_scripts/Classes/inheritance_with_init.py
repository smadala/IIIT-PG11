#!/usr/bin/python 
#   demo of creating subclass-superclass relation of a SHAPE class 


class Shape:						# parent class 

	def __init__( self ):
		self.color = 'black'

class Rectangle(Shape):					# child class 1 

	def __init__( self, w, h ):			# its own constructor 
		Shape.__init__( self)			# parent's constructor 			# What if this is commented out? 
		self.width = w
		self.height = h
 		
	def area( self ):
		return self.width*self.height


class Circle(Shape):					# child class 2 
        
        def __init__( self, r ):
		Shape.__init__( self )			# parent's constructor 			# what if ...  
		self.rad = r
	
	def area(self):
		return 3.14 * self.rad * self.rad 



r = Rectangle( 10, 5 )					# class instance 
c= Circle(8) 						# class instance 

print "Area of the rectangle", r.area() 
print "Area of the circle", c.area() 
print "Width", r.width
print "Height", r.height
print "Radius", c.rad
print "Color of the rectangle is", r.color		# inheritted 
print "Color of the circle is", c.color  			# inheritted 	
