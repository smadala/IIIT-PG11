#!/usr/bin/python 


# Reverses a string recursively 


import sys 


def  RecursiveRev(s):

	if len(s)==1:				# base case 
	
		return s 

	else:					# recursive case 

		return RecursiveRev(s[1:]) + s[0] 		# strip off the first char and append to the end 






s=sys.argv[1]				# hold the input  

print RecursiveRev(s)  			# call the function 



 
