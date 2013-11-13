#!/usr/bin/python 


# demo of the use of the else clause of try...except construct 

# the code opens a file supplied by the user  and reads the lines into a list 

# version 2: With else clause 


import sys

filename=sys.argv[1]


Lines=[]

try:

        f=open(filename)


except IOError:

        print 'Unable to read the file!'

else:

        Lines=f.readlines()             # read the file content into the list 

        f.close()



if Lines:               # if read 

	print Lines


