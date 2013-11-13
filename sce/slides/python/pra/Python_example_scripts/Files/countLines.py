#!/usr/bin/python 

# prints the number of lines of a given file 
# uses the readlines() method of a file object 


import sys

filename=sys.argv[1] 


f=open(filename, 'r') 		# open the file 

lines=f.readlines()		# returns list of the lines 

f.close() 


print "%s has %d lines." % (filename, len(lines) )




		

