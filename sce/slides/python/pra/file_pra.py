#!/usr/bin/python
def mark():
	f=open("marks.txt","r")
	
	lines=f.readlines()
	for line in lines:
		t=0
		data=line.strip().split()
		i=1
		if len(data) == 0:
			continue
		while i < len(data):
			t+=int(data[i])
			i=i+1
			print data[0],"=",t	

	

	"""for word in line.strip():
		t=t+1
		print word,t"""

	"""for val in line.strip():
		print val"""
	


	"""k=1
	t=0
	i=list(i)
	print i
	while k < len(i):
		t+=int(i[k])
		k=k+1"""

		
