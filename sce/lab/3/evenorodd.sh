#!/bin/bash
echo "enter a number:"
read n
#rem=$(($n%2))

if [ $(($n % 2)) -eq 0 ]
then
   echo "$n is an even number"
else 
   echo "$n is an odd number"
fi


