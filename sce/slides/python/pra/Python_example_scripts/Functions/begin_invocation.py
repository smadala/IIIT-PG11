#!/usr/bin/python 

# demo of beginning function invocation  


def func1():

	print 'Hi there' 
	
	str='Hello'
	
	func2(str)		# call f2() 



def func2(s):
	
	print s		



def main(): 

	print 'This is the main function. ' 

	func1()			# call f1() 



if __name__ == '__main__': 		# where should execution start? 
	
	main() 
	#f1()				# If f1() instead of main() ??



