#!/usr/bin/python 


# script to output largest of three integers supplied as command line arguments
 
# version 3: Sequential 

import sys


a=int(sys.argv[1])		

b=int(sys.argv[2])

c=int(sys.argv[3])


max=a 

if b > max: 

	max = b 

if c > max: 

	max = c 

print "Largest is: ", max 


