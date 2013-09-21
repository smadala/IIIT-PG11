#!/bin/bash

echo Echoing special characters \$\'\"\\ 

echo
echo
echo If you want to write multiple lines in single command \
like this then you can end all but the last lines with \
backslash to indicate that line is not ended but is being \
continued. For this to work backslash must be the last \
character on previous line


echo
echo
echo 'Similarly'
ls /usr/loc\
al/bin | wc
echo 'Also works :)'
echo
echo

#You can use all the above techniques directly on shell too

exit 0


