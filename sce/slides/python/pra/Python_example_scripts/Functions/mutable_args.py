#!/usr/bin/python 

# this code snippet demos how passing mutable arguments affect the caller function  

def func(arg):

	print arg 		# ???? 

	L = [20,30,40,50]	# L has local scope 
 
	arg.extend(L)		# modifies the list 
 	
	print arg		# ???? 




L=[i for i in range(11)]   	# create a global list  

func(L)   			# call the function 

				# to avoid mutable changes, pass the copy of L as L[:] 


print L 			# ???? 
	




