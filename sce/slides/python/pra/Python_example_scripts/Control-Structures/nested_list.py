#!/usr/bin/python

# demo of nested lists 

L=[]		# begin with empty list 

for i in range(0,4):

     row=[]			# row is a single list 

     for j in range(0,4):

             row.append(j)	# populate the rows

     L.append(row)		# populate the list (L is list of lists) 


print L

