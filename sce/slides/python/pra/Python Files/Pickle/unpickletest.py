### unpickletest.py
### unpickle file

# import the pickle module
import pickle

# now open a file for reading
# replace filename with the path to the file you created in pickletest.py
unpicklefile = open('filename', 'r')

# now load the list that we pickled into a new object
unpickledlist = pickle.load(unpicklefile)

# close the file, just for safety
unpicklefile.close()

# Try out using the list
for item in unpickledlist:
    print item
