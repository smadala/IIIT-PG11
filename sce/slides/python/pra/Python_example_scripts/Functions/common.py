#!/usr/bin/env python 

# Finds the intersection of two sequence types 

import sys 

#s1=sys.argv[1]
#s2=sys.argv[2] 

def common(s1, s2): 

	L=[]			# start with empty list 
	
	for i in s1:			# traverse s1

		if i in s2:

			L.append(i) 		# found, so add to L 


	return L 


print common([1,2,3,4,5], [2,4,6,8,10])  # both lists 


print common(('Guanine', 'Cytocin', 'Adenine'), ['Adenine', 'Thyamine'])	# tuple and list 


print common("This is string 1", "hide and seek")



# version 2 - Using List comprhension 


#[i for i in s1 if i in s2]


