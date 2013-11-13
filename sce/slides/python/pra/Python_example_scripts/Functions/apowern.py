#!/usr/bin/python 


# computes the value of a**n efficiently 

# n is a positive integer 



import sys



def apowern(a,n):

	'''computes 'a' power 'n' in an efficient manner '''

	# base cases 

	if n==0:
		return 1 


	if n%2==0:				# even 
		
		return apowern(a*a, n/2) 

	else:					# otherwise 

		return a * apowern(a, n-1)





a=int(sys.argv[1])

n=int(sys.argv[2])
 
print apowern(a,n)		# call the function  

