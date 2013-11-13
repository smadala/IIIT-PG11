IFS=$'\n'
if [ -z $cmd ]
then
export cmd=`readlink -f $0`
fi

if [ $# -eq 0 ]
then
	. $cmd "."

elif [ $# -eq 1 ]
then
	if [ ! -e "$1" ]
	then
		echo "Error: Invalid File/Directory!"
		exit 1
	fi
	parent="$1"

	len=${#1}

	((len--))

	if [ ! "$1" = "/" -a  "/" = "${parent:len}" ]
	then
		echo "$parent:"
		parent=${parent:0:len}
	elif [ "$1" = "." ]
	then
		parent="*"
		echo ".:"
	else
		echo "$parent:"
	fi
		
else
	for i in $@
	do
		. $cmd $i
	done
fi


if [  "$parent" = "*" ]
then
	path=*
else 
	path="$parent/*"
fi

for item in $path
do
	if [ "$item" = "$path" ] 	
	then
		break
	fi

	if [ -d "$item" ]
	then
		if [ "$path" = "*" ]
		then
			item="./$item"
		fi

		. "$cmd" "$item"
	else
		echo `basename "$item" `
	fi


done

