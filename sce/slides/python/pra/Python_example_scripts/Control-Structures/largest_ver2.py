#!/usr/bin/python 

# version 2: Comparing each to all 
 
# script to output largest of three integers supplied from command line  


import sys		# for argv[]


a=int(sys.argv[1])

b=int(sys.argv[2])

c=int(sys.argv[3])


if a>=b and a>=c:

        print 'Largest is: ' + str(a)
        
elif b>=a and b>=c: 

        print 'Largest is: ' + str(b)

else: 

	print 'Largest is: ' + str(c)
	


