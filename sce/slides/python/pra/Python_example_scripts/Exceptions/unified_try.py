#!/usr/bin/python 

# demo of unifiying the try/except/else/finally clauses  together 


seq='AGCTA' 

print '====== Exception Thrown and Caught ==========='

try:
	print seq[10]		# index out-of-range 	
	
	#print seq[2]

except IndexError:
	
	print 'Except clause run' 

else:

	print 'else clause run'

finally:

	print 'Finally clause run'


print 'Outside of the try clause' 


print '========= EXCEPTION THROWN BUT NOT CAUGHT ======== \n'

try: 
	out= 5 / 0

except IndexError: 

	print 'EXCEPT CLAUSE RUN' 

else:
	
	print 'ELSE CLAUSE RUN' 

finally:

	print 'FINALLY CLAUSE RUN'



print 'OUTSIDE OF THE TRY CLAUSE' 
	


