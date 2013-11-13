#!/usr/bin/env python 

# A script to add two 3x3 matrices 
# version 1.0 


A=[ [1, 2, 3],
    [4, 5, 6], 
    [7, 8, 9] ]

#B=[[random.random() for i in range(3)]] * 3 

B=[ [3,2,1], 
    [6,5,4],
    [9,8,7] ]

sum=[[0]*3 for i in range(3)] 		# list comprehension
 
					# sum=[[0] * 3] * 3

for i in range(len(A)):

	for j in  range(len(B)): 

		sum[i][j]=A[i][j] + B[i][j] 
		
else:	
	print "The Sum matrix is:\t", sum

