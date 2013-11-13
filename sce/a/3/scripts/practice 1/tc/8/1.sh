
old=`find . -type f  -atime +1 `

echo "$old"
#IFS=$'\n'
for line in "$old"
        do          
		echo "$line"
#                'rm' "$line"
        done

