#!/usr/bin/python 


# code snippet to demo the use of exception arguments 

try: 

#	f=open('IDoNotExist.txt')		
	
#	f=open('NoReadPermission.txt')		# opening a file with no read permission

	f=open('/etc/')				# opening a directory 

except IOError, e: 		# e is the exception argument 


	print 'Something went Wrong' 



print e 		# the exception argument gives details 



