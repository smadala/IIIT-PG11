#!/usr/bin/python 


# demo of Default Argument Matching in Python



def func(name, age=100): 


	print "Name:", name 


	print "Age:", age 

	return 



# Now, call the function 


func('Alice',21) 

print '-----------------------------------------------'

func ('Alice') 

print '------------------------------------------------'

func(name='Bob') 						# keyword argument 



