
IFS=$'\n'
if [ ! -d "/home/$USER/TRASH" ]
then
	mkdir "/home/$USER/TRASH"
fi
	

if [ $# -ne 0 ]
then

	for i in $@
	do
		if [ ! -f "$i" ]
		then
			echo " Error: Invalid File!"
			continue
		fi
		
		file "$i" | awk -F":" '{ print $2 }' | grep -E 'gzip' > /dev/null
	
		if [ $? -ne 0 ]
		then
			gzip "$i"
			i="$i.gz"
		fi
	
		mv $i "/home/$USER/TRASH" 
	done
	
fi

old=`find "/home/$USER/TRASH" -type f  -ctime +1 `

	for line in $old
	do	
		rm "$line"
	done

