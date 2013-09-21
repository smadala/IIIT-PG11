#!/bin/bash

function isValid
{
echo $1 | grep -E '[\-]?[0-9]+.[0-9]+' > /dev/null

if [ $? -ne 0 ]
then
return 1
fi
return 0
}

isValid $1

if [ $? -ne 0 ]
then
 echo "please provide float $1"
 exit 1
fi

isValid $2

if [ $? -ne 0 ]
then
 echo "please provide float $2"
 exit 1
fi
echo "+-/%"
read -n 1 op
while :
do
#  read -n 1 op
  case "$op" in 
     +)  echo $1+$2|bc
        ;;  
     /)  echo $1/$2|bc
         ;;
     
  esac
  echo "continue?:"
  read -n 1 op
  if [ $op == "n" ]
  then
   echo "Byee"
    break
  fi
done


