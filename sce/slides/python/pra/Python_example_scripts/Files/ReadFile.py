#!/usr/bin/python 


# code snippet to demo reading a file in Python 

f=open('test.txt') 		# open the file first 


print f 			# print file values 

		
str=f.read()			# entire file read into string 


#str=f.read(50)			# the first 5 characters 


print str 


#print str.split()  

f.close()			# close the file 

