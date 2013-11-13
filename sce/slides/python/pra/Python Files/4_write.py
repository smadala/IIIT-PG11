#!/usr/bin/python

#-------------------------
#SYNTAX:
#fileObject.write(string);
#-------------------------


# Open a file
fo = open("/tmp/foo.txt", "wb")
fo.write( "Python is a great language.\nYeah its great!!\n");

# Close opend file
fo.close()
