#!/bin/bassh
#content=$(cat $1)

read -N 10000 content < $1

len=${#content}
len=$((len-1))
echo $len

#len=-1
while [ $len -ge 0 ]
do
c=${content:len:1}
len=$((len-1))
echo -n "$c"
done


#cat $1
#echo -e "ravi\\nkumar"




