#!/usr/bin/python 

# reads marks from a file and does the sum calculation 


f = open("marks.txt")

	
for line in f:


		name, mid1, mid2, final = line.split() 		# split each line into attributes 

	
		Total = float(mid1) +  float(mid2) + float(final)  	# cumulative sum of the marks 

	
		print name, "\t ", Total


f.close() 



