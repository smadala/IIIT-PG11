#!/usr/bin/python
import sys,getopt
from sys import argv
def feb(i):
	if   i == 0:
		return 0
	elif i == 1:
		return 1
	else:
		return feb(i-1)+feb(i-2)
print sys.argv
n=len(sys.argv)
l=argv[1:]
optlist,args=getopt.getopt(l,"ak:f:");
print optlist
print args
'''while n > i:
i=1
	print feb(int(sys.argv[i]))
	i=i+1'''


		
