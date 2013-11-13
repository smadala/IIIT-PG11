## pickletest.py
### PICKLE AN OBJECT

# import the pickle module
import pickle

# lets create something to be pickled
# How about a list?
picklelist = ['one',2,'three','four',5,'can you count?']

# now create a file
# replace filename with the file you want to create
file = open('filename', 'w')

# now let's pickle picklelist
pickle.dump(picklelist,file)

# close the file, and your pickling is complete
file.close()
