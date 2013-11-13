#!/usr/bin/python 

# Print some attributes of a given file 

import sys 

filename=sys.argv[1] 


fo=open(filename, 'r')


print "Name: ", fo.name 

print "Mode: ", fo.mode


print "Closed, right? ", fo.closed


fo.close() 


print "Closed, right? ", fo.closed
 
