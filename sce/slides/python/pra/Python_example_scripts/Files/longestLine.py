#!/usr/bin/python 

# prints the longest line of a file supplied via the command line

import sys 


def LongestLine(filename):

	'''Finds and prints the longest line of a given file''' 

	f = open(filename)

	longest_str = "" 			# assume longest is empty


	for line in f: 					#Search for longest 

		if len(line) > len(longest_str):


				longest_str = line				# found 


	print "Longest line =", len(longest_str)
	
	print longest_str




filename= sys.argv[1]		# input from command line 

LongestLine(filename) 		# call the function 


	


