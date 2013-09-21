function chettu(){
	for item in $1/*
	do
		if [ "$item" = "$1/*" ]
		then
			break
		fi

		echo "$2|-- ` basename $item`"

		if [ -d "$item" ]
		then
#		echo "---dir $item" 
			space="|   $2"
			chettu "$item" "$space"
		fi
	done
}

if [ $# -ne 1 ]
then
	echo "Error: Invalid Number of Arguments!" >&2
	exit 1
fi

if [ ! -d $1 ]
then
	echo "Error: Input not a directory" >&2
	exit 1
fi


echo "$1"

chettu $1
