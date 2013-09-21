echo "enter file name:\c"
read fname
if [ -f $fname ]
then
	if [ -w $fname ]
	then
		echo "type some test"
		cat >> $fname
	else
		echo "no permission"
	fi
fi
