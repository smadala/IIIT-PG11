#!/usr/bin/python 

# tests if a string is palindrome of not recursively


import sys 

s=str(sys.argv[1] )

 
def palindrome(s): 

	try: 
	
			if len(s) == 0 or len(s)==1:
				return 'Palindrome'

			if s[0] != s[-1]:
				
				return "Not Palindrome"

			else:

				return palindrome(s[1:-1])	# strip off the first and last chars 

	
	except: IndexError


print palindrome(s) 



