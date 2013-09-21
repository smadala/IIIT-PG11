#!/bin/sh
echo "What is your name [ `whoami` ] ?"
read myname
if [ -z "$myname" ]; then # -z tests if myname is a non empty string
myname=`whoami`
fi
echo "Your name is : $myname"
