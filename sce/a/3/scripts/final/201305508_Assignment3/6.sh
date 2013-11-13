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
			space="|   $2"
			chettu "$item" "$space"
		fi
	done
}

if [ $# -ne 1 ]
then
	echo "Error: Invalid Number of Arguments!"
	exit 1
fi

if [ ! -d $1 ]
then
	echo "Error: Input not a directory"
	exit 1
fi


echo "$1"

chettu $1
