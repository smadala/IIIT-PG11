#!/bin/python

# Default values for arguments
def default(flag=0, text='Default'):
	if flag==0:
		print 'false'
	else:
		print text

default(1, 'Hello World')		# will print true.
default(1)				# will print false, takes default value of 0.
default()
default(text='Hi', flag=1)		# arguments can be specified in any order.
