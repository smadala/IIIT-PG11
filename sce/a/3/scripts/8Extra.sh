
IFS=$'\n'
if [ ! -d "/home/$USER/TRASH" ]
then
	mkdir "/home/$USER/TRASH"
fi
	

if [ $# -ne 0 ]
then

	for i in $@
	do
		if [ ! -e "$i" ]
		then
			echo "Error: Invalid File/Directory!"
			continue
		fi

		gzip -r "$i"
		if [ -f "$i"  ]
		then
		
		file "$i" | awk -F":" '{ print $2 }' | grep -E 'gzip' > /dev/null
		if [ $? -ne 0 ]
		then		
			i="$i.gz"
		fi
		fi
	
		mv "$i" "/home/$USER/TRASH" 
	done
	
fi

old=`find "/home/$USER/TRASH" -type f  -ctime +1 `

	for line in $old
	do	
		rm -r "$line"
	done

