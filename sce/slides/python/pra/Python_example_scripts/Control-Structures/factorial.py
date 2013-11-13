#!/usr/bin/python

# reads a number from command line and computes the factorial of it. 

import sys 


n=int(sys.argv[1]) 

fact=1 

for i in range(1,n+1):

         fact=fact*i	

print 'Factorial of ', n, 'is: ', fact



