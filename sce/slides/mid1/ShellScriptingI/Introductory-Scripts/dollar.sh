#!/bin/bash

count=0

for t in "$@"
do
 echo ${t}word
if [  -z "$t" ] 
then 
  echo "$(($count+1)) is empty" 
fi
 count=$(($count+1))
done
 echo $count
 echo ${5:-`whoami`}
