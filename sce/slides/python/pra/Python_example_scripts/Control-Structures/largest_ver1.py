#!/usr/bin/python 

# script to output the largest of three integers supplied as command line arguments 
# version 1 

import sys 


a=int(sys.argv[1])

b=int(sys.argv[2])

c=int(sys.argv[3])


if a>=b:
	if a>=c:
		print 'Largest is: ' + str(a) 
	else:
		print 'Largest is: ' + str(c)

else: 
	
	if b>=c:
		print 'Largest is: ' + str(b) 

	else: 
		print 'Largest is: ' + str(c)


		
