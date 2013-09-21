#!/bin/bash

ls .  #ls current directory
ls .. #ls parent directory

echo "Parent process ID is $$"
echo
echo

echo "Going to call helper script as child"
A="Parents secret value of A"
./12-special_characters-dot-helper.sh
echo "You can see this"
echo
echo


echo "Going to source helper script"
. ./12-special_characters-dot-helper.sh
echo "You wont see this!!"
echo
echo

exit 0 

