#!/bin/python

import sys

# Function with command line arguments
def display(args):
	print 'Number of arguments passed = ', len(args)
	print 'Arguments passed = ', str(args)

display(sys.argv)		# sys.argv = arguments passed from the command line

