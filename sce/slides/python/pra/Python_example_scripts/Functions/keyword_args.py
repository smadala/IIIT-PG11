#!/usr/bin/python 


# demo of Keyword argument matching mode (i.e. matched by name)


def func(name, age, city):

	print 'Name: ', name
	print 'Age: ', age 
	print 'City: ', city 


 
# call the function now 


func(age=20, city='New York', name='Bob')  			# notice the orders 

print '\n'

func(city='Hyderabad', name='Kumar', age=45) 				



