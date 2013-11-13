#!/usr/bin/env python 

# Given a list of numbers, this script outputs the max item 
 

L=range(2,100,4)		# begin with this list

max=L[0]			# let the first item be max

for i in L:

	if i > max: 

		max=i   	# update max

print "Max of", L, 'is\t' +  str(max)



