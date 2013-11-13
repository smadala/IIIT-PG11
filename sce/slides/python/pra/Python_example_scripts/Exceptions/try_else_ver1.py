#!/usr/bin/python 


# demo of the use of the else clause of try...except construct 

# the code opens a file supplied by the user  and reads the lines into a list 

# version 1: no else clause 


import sys 

filename=sys.argv[1] 


Lines=[]

try: 


	f=open(filename) 

	Lines=f.readlines()		# read into the list 

	f.close() 

except IOError: 

	print 'Sorry, unable to open the file. ' 


if Lines:		# if read 

	print Lines 


