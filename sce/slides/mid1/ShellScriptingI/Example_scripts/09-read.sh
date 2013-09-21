#!/bin/bash

#-n option causes echo not to terminate what is echoed with \n
echo -n 'A. Enter your name : '
read name
echo 'A. You entered your name as' $name
echo 
echo


#When multiple variable names are specified read will put 
#first word separated by IFS in first variable,
#second word in second variable and all the remaining
#in last word
echo -n 'B. Enter your name as <first_name> <last_name> : ' 
read first_name last_name
echo "B. Your first_name is $first_name and your last_name is $last_name"
echo
echo


#When values are more than variables, last variable gets
#all remaining values
echo -n 'C. Enter sentence with five or more words : '
read first_word second_word third_word extra
echo "C. Words are 1. $first_word, 2. $second_word, 3. $third_word, remaining words are $extra"
echo
echo


#When values are less other variables get empty values
echo -n 'D. Enter one single word : '
read first_word second_word third_word extra
echo "D. Words are 1. $first_word, 2. $second_word, 3. $third_word, remaining words are $extra"
echo
echo


#Reading values as arrays
echo -n 'E. Enter as many values as you want : '
read -a values
echo "E. 0=${values[0]}, 1=${values[1]}, 2=${values[2]}, not printing rest as do not know loops yet :("
echo
echo



#Read with timeout
echo -n 'F. Do not enter anything for next five seconds : '
read -t 5 timed_out
#We should capture return value in variable before doing
#Any other operation, else $? will have return value of 
#next operation and we will loose previous return value
RETURN_VALUE=$?

#Below we are checking for return value of read
#If it is not equal to 0 then read error or timeout
#If return value is zero then read was succesfull

#Do not try to learn if from this example
if [ "$RETURN_VALUE" -eq "1" ]
then
	echo
	echo "F. Read timed out"
else
	echo "F. You entered text within five second :'("
fi
#Uncomment below line to explicitly print return value
#echo "RETURN_VALUE is $RETURN_VALUE"
echo
echo



#Read first 'n' characters
echo -n 'G. Enter five characters, no need to press return/enter key : '
read -n 5 fivechar
echo
echo "G. You entered $fivechar"
echo
echo



#Non-echoed read
echo "H. Enter your password : "
read -s password
echo "H. Your password is $password. (This script is good hacker, it captured your password.)"
echo 
echo


echo "Read man page of read to learn how to use read to display prompt "
echo "on error output before read (-p), or to ignore \ as line "
echo "continuation character (-r), or to read from other file descriptors "
echo "(-u)."

exit 0

