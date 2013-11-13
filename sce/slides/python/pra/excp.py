#!/usr/bin/python
import sys,traceback

try:
	n=int(sys.argv[1])
	print n
except (ValueError,IndexError):
	traceback.exc(file=sys.stdout)
	print "value error"
except IOError:
	print "Name Error"
else:
	print "else part when no exception"
finally:
	sys.stdout.write("running finally\n");
'''except NameError:
	print "name error"
	print "-"*10
except IndexError:
	print "index error"'''





