#!/usr/bin/python 

#prompts for n and prints the first n lines of a user-supplied file 


file = open(raw_input('enter file: '))		# prompt and open 

Lines = file.readlines() 		# lines returned in list

file.close() 


num = input('Enter number of lines: ')


for i in range(num):

	print "Line ",  i+1,  ":  ", Lines[i], 
	
	
