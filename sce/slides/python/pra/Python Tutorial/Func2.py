#!/bin/python

from math import sqrt

# Function returning a value
def prime(n):
	for j in range(2,int(sqrt(n))):
		if n%j==0:
                	return 'False'
	return 'True'

x = prime(3)
print x