#!/usr/bin/python 


# Recursivelly finds the factorial of a number supplied from command line 



import sys 


def fact(n):
		
	if n<=1:			# base case 

		return 1 


	else: 				# recursive case 


		return n * fact(n-1) 



num=int(sys.argv[1]) 		# input 


result= fact(num) 		# function call 


print "Factorial of %d is %d" %(num, result) 



