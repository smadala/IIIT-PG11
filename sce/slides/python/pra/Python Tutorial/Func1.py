#!/bin/python

# Simple function
def example():
	"""This function prints a message"""	# documentation of the function
	print 'Hello World'

example()				# Function call

# Functions as objects
print example.func_doc			#Prints documentation of function
print example.func_name			# Prints name of the function