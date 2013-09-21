#!/bin/bash

echo "enter the number "
read n
c=0
while [ $n -gt 0 ]
do
#  c=$(($c+1))
 ((c++))
  n=$(($n/10))
done
echo "number of digits: $c"
