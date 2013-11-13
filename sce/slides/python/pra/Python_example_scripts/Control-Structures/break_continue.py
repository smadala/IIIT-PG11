#!/usr/bin/env python 


# a script to demo the use of break, continue, and pass statements 


for k in range(1,51):

	if k == 4:

		pass 			# Do nothing 
		#print k
	elif k % 3 == 0:

		continue

	elif k % 11 == 0: 

		break 

	else:
		print k

print "See ya!" 


		
