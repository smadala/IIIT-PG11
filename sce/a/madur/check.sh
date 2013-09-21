echo "user name:\c "
read lname

time=0

while true
do
	who | grep "$lname" > /dev/null
	if [ $? -eq 0 ]
	then
		echo "$lname has logged in."
		if [ $time -ne 0 ]
		then
			echo "$time late"
		fi
		exit
	else
		time=`expr $time + 1`
		sleep 60
	fi
done

