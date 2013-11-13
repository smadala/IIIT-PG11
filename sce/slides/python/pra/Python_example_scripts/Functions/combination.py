#!/usr/bin/python 


# computes the value of C(n,k) recursively 

import sys 

def comb(n,k):

	# base case 

	if k==0 :
		return 1 

	if n==k: 
		return 1 

	# recursive case 

	return comb(n-1,k) + comb(n-1,k-1) 


n=int(sys.argv[1]) 

k=int(sys.argv[2]) 

print comb(n,k) 		# call the function 




