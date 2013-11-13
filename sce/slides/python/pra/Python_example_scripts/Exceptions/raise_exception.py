#!/usr/bin/python 

# demo of raising an exception when a wrong DNA character is encountered 



def DNA_check(dna,  allowed='tgac'): 

	'''raise exception demo '''

	for i in dna:	

		if i not in allowed:
	
			raise ValueError, "%s not in %s"  % (i, allowed) 


#DNA_check('gtac') 

DNA_check('uct')

		
