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

cd $1

for item in *
do
	lower=`echo $item | tr A-Z a-z`


	if [ "$lower" = "$item" ]
	then
		continue;
	fi

	if [ -f "$lower" -o -d "$lower" ]
	then
		echo "Warning: Not overwriting $lower"
		continue;
	fi
	mv "$item" "$lower"
done

