#!/usr/bin/python 

# demo of the try...finally construct 



try: 

	n=float(raw_input('Enter your number:'))


	double = 2 * n 


finally: 

	print 'Who can stop me from executing?' 


print 'Double=', double 



