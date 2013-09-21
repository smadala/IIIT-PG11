#!/bin/bash

:
echo "Return value of : is $?, that is true "
echo
echo

#infinite loop, while true
while :
do
	echo -n "We are in infinite loop. Write 'end' to end loop : "
	read value1
	if [ "$value1" != "end" ] 
	then
		:	#Do nothing if not equal
	else
		break
	fi
done
echo
echo


#Anonymous here documents
echo "Created here document in code below this echo"
: <<thisisawesome$$$234
These are comments not preceeded with #
You will learn about here documents later in 
shell scripting lectures. Here documents
are very useful in creating documents, passing
input to other commands.
thisisawesome$$$234
echo
echo


echo 'Checking if $HOSTNAME, $USER and $HOME are set'
#Ignore use of ${<variable??'error message'} syntax
#It will be convered later
: ${HOSTNAME?} ${USER?} ${HOME?}
echo 'If no error message preceeded then variables were set'
echo


echo ': can also be used to truncate files or create empty files'
: > abc.txt
ls -l abc.txt
echo
echo
echo 'Adding text to abc.txt'
echo 'This is some text' > abc.txt
echo 'abc.txt contains:'
cat abc.txt

echo
echo
echo 'Truncating abc.txt with :'
: > abc.txt
echo 'abc.txt contains:'
cat abc.txt
echo
echo
rm -f abc.txt


exit 0

