#!/usr/bin/python

def tower(n,s,d,a):
	if n==1:
		print "move disk 1 from ",s,"to",d
		return
	tower(n-1,s,a,d)
	print "move disk %d" %(n),s,"to",d
	tower(n-1,a,d,s)
n=input("enter disk:")
tower(n,'A','C','B')

