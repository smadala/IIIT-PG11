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

cd $1

for item in *
do
	lower=`echo $item | tr A-Z a-z`

	echo "$item --> $lower"

	if [ "$lower" = "$item" ]
	then
		continue;
	fi

	if [ -f "$lower" -o -d "$lower" ]
	then
		echo "Warning: Not overwriting $lower" >&2
		continue;
	fi
	mv "$item" "$lower"
done


