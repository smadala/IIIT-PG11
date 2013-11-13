#!/usr/bin/python 


# demo of Variable-length argument matching in Python


def func(name, *T):				# notice the asterisk (*) 

	print "Hi ", name 

	for i in T:

		print i 



# now call the function  


func('Alice') 			

print '---------------------------------------' 

func('Bob', 'Joyce', 'Sunder', 'Krishnan') 			# call with more arguments than defined 

print '---------------------------------------' 


func('Anonymous', (3,2), 1, 'Boooom!')				# pass the tuple T as arg 
 
print '\n'
