#!/bin/bash

file `locate keyring.png`


echo
echo
A=`ls /bin | wc -l`
B=`ls /sbin | wc -l`
#Same as before ignore use of $(( ))
C=$(($A+$B))
echo "Total files in /bin ($A) and /sbin ($B) are $C" 

exit 0

