#the writelines() and readlines() methods in Python do not handle EOL characters on your behalf, making the naming a bit confusing. In this example, note the inclusion of the \n character in the elements of the list.

#writelines demo:

colors = ['red\n', 'yellow\n', 'blue\n']
f = open('colors.txt', 'w')
f.writelines(colors)
f.close()

#readlines demo:
f = open('colors.txt')
f.readlines()
f.close()

# for large files, reading the contents into memory can be impractical. So it is best to use the file object itself as an iterator, which will consume content from the file as needed with no intermediary memory requirement

f = open('colors.txt')
for line in f:
	print line,
f.close();

# It is a good practice to use exception handling as well.

