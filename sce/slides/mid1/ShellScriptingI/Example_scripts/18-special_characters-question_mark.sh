#!/bin/bash

#? can be used as ternary operator as used in C when used in $(( ))
A=$((2>3?1:0))
echo "1. 2>3 is $A (1->true, 0->false)"
echo
echo


#Note that there is no preceding dollar for B when used inside $(( )) to
#access the value of B.
B=50
C=$((B>25?100:10))
echo "2. If B>25 then C is 100 else it is 10. That is with \$B as $B we get \$C as $C"
echo
echo


#We can use $ in front of B, that works too!!
C=$(($B>25?100:10))
echo "3. If B>25 then C is 100 else it is 10. That is with \$B as $B we get \$C as $C"
echo
echo



#? is used as single character wild-card to match with any single character
echo "4. Files that have any single character, then 0, then - and then anything are : "
echo  ?0-*
echo
echo



#? can be used to check if variable is set or not
D='I am set'
# E='I am not set'

#Following line would print D as it is set
echo "5. Value of D is" ${D?'D is not set'}

#Following line would print error and stop execution of shell script
#The error message would include name of script, line number etc.
#information to help with debugging
echo "6. Value of E is" ${E?'E is not set'} 

#This line wont execute because shell script stops when
#We test for E above which is not set
echo "This wont execute because of error above"


exit 0

