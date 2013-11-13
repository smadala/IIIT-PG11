#!/usr/bin/python 

# a demo of the loop else block 

# Test whether a commandline-supplied number is prime or not (Primality test)

 
import sys 		# for argv[]

import math 		# for sqrt() 

n=int(sys.argv[1]) 		  # n>=2


root=math.sqrt(n)		# take square root of n 

for i in range(2,int(root)+1):
								
	if (n % i) == 0:		# has a factor ?
 	
		print n, 'is NOT prime because ', i, 'divides it!' 

		break 

else: 					    # this block executed if the sequence has been exhausted. 
	print n, 'is a prime number'	    # the break statement skips this block. 


print "Good Bye!" 

