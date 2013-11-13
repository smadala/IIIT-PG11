#!/usr/bin/python 


# code snippet to recursively add the first n natural numbers 
 
# n is read from command line 


import sys 



def RecursiveSum(n): 

	if n == 0: 		# base case 
		
		return 0 
	else: 				# recursive case 
	
		return n + RecursiveSum(n-1) 		





n=int(sys.argv[1] ) 


print RecursiveSum(n) 		# do the addition  
