#!/usr/bin/python 

# this code snippet demos how passing immutable arguments UNaffect the caller function   



def func(T): 

	print T				# ??? 

	T += (20,30,40,50) 		# new tuple with local scope    

	print T				# ??? 
	



T=(0,1,2,3,4,5,6,7,8,9,10) 		

func(T) 					# call the function 

print T 					# ????
	
