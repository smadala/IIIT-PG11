#!/bin/bash

# validate numeric arguments 

IsValid()
{
#let n=$1+1 >/dev/null #2>&1                # add 1 to command-line input and see exit status 

echo $1 | grep "^[0-9]\+$" > /dev/null

echo "Command executed with exit status of $?"
 
if [ $? -ne 0 ]
then 
echo "$1 is non-numeric. Numeric Input Expected!" ; exit 1

#else
# do something with the validated numbers. 

fi 

return 
}

# call the function
IsValid $1 

IsValid $2 


