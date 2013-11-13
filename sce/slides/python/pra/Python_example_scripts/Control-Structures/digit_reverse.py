#!/usr/bin/env python 

# script to print the sum of digits of a given integer from a command line 


import sys 

num=int(sys.argv[1])	# convert to int 

while num:
	rem=num % 10	# holds remainder 
	
	quot=num / 10	# holds the quotient 
	
	num=quot	
	sys.stdout.write(str(rem))

print '\n'

