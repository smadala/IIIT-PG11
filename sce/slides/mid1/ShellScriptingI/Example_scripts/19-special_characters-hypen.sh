#!/bin/bash

#Hypens have been used to supply arguments to commands 
echo "A. Listing all files including hidden files in current folder, should show . and .."
ls -a
echo 
echo


#Hypens can be used in parameter substitution ${} to indicate default value
#Use default value in case variable is not set
#B=   #B is not set
C=    #C is set to null
echo "B. Value of \$B is ${B-'B is not set'}"
echo "C. Value of \$C is ${C-'C is not set'}"
echo
echo


#We can also use Hypens to check for non-null values
#D=   #D is not set, hence null
E=    #E is set to null
echo "D. Value of \$D is ${D:-'D is null'}"
echo "E. Value of \$E is ${E:-'E is null'}"
echo
echo


#
#Double -- are used to specify long options 
echo "F. Listing first 10 files / directories with size in human readable format"
ls -l --human-readable | head
echo
echo
#Interested students can read 'man -a getopt' to see man pages
#of getopt functions that help programmers in processing options
#supplied as command line arguments.


#One very interesting use of -- is to indicate end of options
#So that all following - are treated as part of argument (filename) etc.
#and not as options.
echo "G. Creating file which is hard to delete"
touch -- -can_you_delete_me
ls -l -- -can_you_delete_me
echo "G. Try to delete above file manually"
echo
echo
#To delete above file use
#rm -f -- -can_you_delete_me
#   Note that only when programmers know the above indicator for
#end of options or use getopt libraries, which are designed to 
#understand above indicators, -- will work properly. if some 
#novice programmer tries to parse options manually in code without
#using getopt and does not writes proper rules for evaulation
#of -- then the above technique will not work. The working of --
#depends on program (library used) and not on bash




#One of the very powerful function of - is to allow use of
#Standard Input (stdin) or Standard Ouput (stdout) as argument
#to programs which operate on files.
#   We have used <,  > or | in past to redirect contents of file to
#stdin or stdout or stdout of one program to stdin of another. -
#allows us to use stdin and stdout as file which is somewhat opposite
#of what < or > do. Since we have only one operator - it will be
#used to read from stdin and write to stdout whenever it is used
#in place of filename in commands.
#   Please read the following examples carefully, as use of -
#in this manner is little confusing when you see it for first time


#Asking cat to read from stdin and write to abc.txt
echo "H. Write few lines of text, press Ctrl+D to end"
cat - > abc.txt
echo 
echo "H. abc.txt contains:"
more abc.txt
echo
echo "H. Deleting abc.txt to keep directly clean :) "
rm -f abc.txt
echo
echo 
#Note that we can do the same with "cat > abc.txt" but that is
#because when command line arguments are missing cat reads from
#stdin. In the above example (H) cat is not reading from stdin
#directly, it is reading from - which has same contents as stdin


#Doing something better with -
#Ignore use () to create sub-shells. That would be covered in future
#lectures / examples
echo "I. Creating folder 1 and sub-folders and files inside it"
mkdir -p 1/2/3/4
touch 1/a.txt 1/2/b.txt 1/2/3/c.txt 1/2/3/4.txt
mkdir -p 1/abc 1/2/def 1/2/3/ghi
echo "I. Tree of 1 looks like"
tree 1
echo
echo "I. Now creating folder A and copying 1 with sub-folders and files inside 2"
mkdir A
tar cf - 1 | (cd A; tar xf -) #The main command for this example
			      #Allows copying folder 1 along with sub-folders
			      #and files to folder A using tar
			      #Notice that one tar is writing to -
			      #and other is reading from -
echo "I. Now tree of A is"
tree A
echo 
echo "I. Deleting both 1 and A to keep directory clean :) "
rm -rf 1 A
echo
echo


#Since tar is capable of reading and writing from/to stdin/stdout
#The above example also does not really give anything extra with -
#Hence below is another example of using - to Prepend lines to file
#We can use >> to append lines to file, but to prepend below
#technique can be used
echo "This is first line" > first.txt
echo "J. We have file first.txt with contents:"
more first.txt
echo
echo "J. Prepeding new first line to file"
echo "This is new first line" | cat - first.txt > first_new.txt
#Why not do > first.txt in above line directly? Why do the 
#redirection with two commands?
mv first_new.txt first.txt
echo "J. first.txt now contains:"
more first.txt
echo
echo "J. Deleting first.txt"
rm -f first.txt
echo
echo


#Last example of - as stdin/stdout . By now things should be self-explanatory
echo "K. Comparing lines that contain echo in 01-hello_world.sh with file 06-shell_variables.sh"
grep echo 01-hello_world.sh | diff 06-shell_variables.sh -
echo
echo


#- can be used as argument to cd to go to $OLDPWD
echo "L. Will go from current directory($PWD) to / and come back using cd -"
( #Ignore use () for creating sub-shells
	echo
	echo "In $PWD"
	echo
	cd /
	echo "Now in $PWD"
	echo
	cd - >/dev/null   #Can also be done using cd $OLDPWD
			  #For some reason cd seems to echo $PWD so redirecting output to
			  #/dev/null 
	echo "Now back in $PWD"
	echo
)
echo
echo
#Note that some other commands like su also treat - for special
#purposes


#Last use of - is for subtraction in arithmetic expressions
echo "4 - 1 is " $((4-1))
echo
echo


exit 0

