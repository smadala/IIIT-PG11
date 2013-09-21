#!/bin/bash

#~ can be used to find home directories of users
echo "Home directory of current user is" ~
echo "Home directory of mysql is" ~mysql
echo "Home directory of root user is " ~root
echo
echo

#~+ can be used to check $PWD
echo "We are in " ~+
echo
echo


#~- can be used to check $OLDPWD
(
	echo "We are in " ~+
	cd ..
	echo "Now we are in " ~+
	echo "Previously we were in " ~-
)
echo
echo


exit 0 

