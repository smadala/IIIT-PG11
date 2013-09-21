if [ $# -ne 0 ]
then

	for i in $@
	do
		if [ ! -f "$i" ]
		then
			echo " Error: Invalid File!"
			continue
		fi
		
		file "$i" | awk -F":" '{ print $2 }' | grep 'gzip' > /dev/null
	
		if [ $? -ne 0 ]
		then
			gzip "$i"
			i="$i.gz"
		fi
	
		mv $i ~/TRASH 
	done
	
fi

#access time or change time
old=`find ~/TRASH -type f  -atime +1 `

IFS=$'\n'
	for line in $old
	do	
		'rm' "$line"
	done

