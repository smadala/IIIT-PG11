#!/usr/bin/python

# Reverse each line of a file and print 


f = open('test.txt', 'r')


line = f.readline()


while line:
	
		L = list(line)			#  creates list of a line 
			
		L.reverse()			# reverse
		 
		print "".join(L)		# convert back to string 

		line = f.readline()		# move to next line 


for line in f:

	        print line

