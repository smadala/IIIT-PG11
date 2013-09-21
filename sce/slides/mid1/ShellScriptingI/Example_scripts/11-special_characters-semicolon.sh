#!/bin/bash

clear; ls 	#clears screen and then does ls

#-d tests whether given argument is a directory
#avoid learning if from here, we would cover it
#later in the lecture

if [ -d . ] ; then
	echo "Current folder is a directory, what a surprise!"
else
	echo "Current folder is not a directory. This is not possbile."
fi




#Do not try to learn case statement from here
#This is just to indicate use of ;
#It would make sense while revising after you have
#studies case statement

A=abc
case "$A" in
	abc)	
		echo "This will get echoed"
		;;

	def)	
		echo "Try to get this printed"
		;;
esac

exit 0

