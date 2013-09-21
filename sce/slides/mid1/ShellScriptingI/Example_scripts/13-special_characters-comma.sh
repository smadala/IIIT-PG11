#!/bin/bash

#When comma is used in arithmetic operations,
#value of last expression is return value and
#hence that gets assigned to variable on left
#
#Ignore $(( )) operator for now
A=$((4,56))
echo $A



#Comma can be used to specify multiple options
#on command line which have some common part
#It concatenates various parts sorrouding , with
#each of different values separated by comma
echo -n "No of files in /usr/bin is "
ls /usr/bin | wc -l
echo -n "No of files in /usr/local/bin is "
ls /usr/local/bin | wc -l
echo -n "Total files = "
ls /usr/bin /usr/local/bin | wc -l
echo -n "Which is same as "
ls /usr{,/local}/bin | wc -l


#More complex example
echo -n "No of files in" {,/usr{,/local}}/{,s}bin "are: "
ls {,/usr{,/local}}/{,s}bin | wc -l

exit 0


