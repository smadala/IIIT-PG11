#!/usr/bin/python 

# script to simulate the copy() command 

import sys 

source=sys.argv[1]

dest=sys.argv[2] 



def copy(source,dest):

	f1=open(source)		# open for reading 

	f2=open(dest,'w')	# open for writing 


	for line in f1: 
	

		f2.write(line)
	


	# close the files 

	f1.close() 

	f2.close() 



# function call 

copy(source,dest) 



