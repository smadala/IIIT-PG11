#!/usr/bin/python 

# Simple multiway  test 

richter=input('Enter the magnitude of the earthquake:') 

if richter < 4.0:

	print 'Minor' 

elif 4.0 < richter < 6.0: 		# chained conditional is posssible 

	print 'Moderate' 

else: 
	print 'Major' 
