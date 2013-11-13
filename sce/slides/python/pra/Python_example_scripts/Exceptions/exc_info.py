#!/usr/bin/python 

# alternative way of accessing additional information about an exception 

# using the exc_info() method of the sys module

# What we get from method:  the exception object, the instance object (= exception arg) and the traceback object. 



try: 

	float('wrong argument')

except:

	import sys	

	T=sys.exc_info()	# save the info to a tuple variable

print T 


for i in T: 

	print i 
