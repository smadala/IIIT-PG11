#!/bin/bash
oldIFS=$IFS
IFS=" "
var=`cat 1.txt`
#var=$(cat 1.txt)
echo $var
IFS=$oldIFS
