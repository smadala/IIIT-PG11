#!/usr/bin/python

#-------------------------
#SYNTAX:
#fileObject.read([count]);
#------------------------

# Open a file
fo = open("/tmp/foo.txt", "r+")
str = fo.read(10);
print "Read String is : ", str
# Close opend file
fo.close()


