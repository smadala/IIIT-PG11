if [ -z $cmd ]
then
export cmd=`readlink -f $0`
fi


if [ $# -eq 0 ]
then
#parent=*
	. $cmd "."

elif [ $# -eq 1 ]
then
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

#if [ "$parent" = "*" ]
#then
#	echo ".:"
#	parent="."
#
#else
#	echo "./$parent:"
#fi



for item in $parent/*
do
	if [ "$item" = "$parent/*" ] 	
	then
		break
	fi

#echo  `basename $item`
	if [ -d "$item" ]
	then
#		echo "$cmd" "$i"
 
#       echo  "$item:"
		if [ "$parent" = "*" ]
		then
			item="./$item"
		fi

		. "$cmd" "$item"
	else
		echo `basename "$item" `
	fi


done

#echo 

#for i in $parent/* 
#do
##sleep 1
#	if [ "$i" = "$parent/*" ]
#	then
#		break
#	fi
#
#	if [ -d "$i" ]
#	then
##		echo "$cmd" "$i"
# 
#		. "$cmd" "$i"
#	fi
#done



