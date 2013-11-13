#!/usr/bin/python 

# prints the first n Fibonacci series 
# n is supplied from command line 

import sys 

n=int(sys.argv[1]) 


fib1=0 

fib2=1 

sys.stdout.write(str(fib1))	

sys.stdout.write(' ')  	 # print space      print(str(fib1), end='') in 3.0+


sys.stdout.write(str(fib2))

sys.stdout.write(' ')  


for i in range(1,n-1):
	
	fib3=fib1 + fib2
	
	sys.stdout.write(str(fib3)) 

	sys.stdout.write(' ')	# print space 

	fib1=fib2

	fib2=fib3 


print 




