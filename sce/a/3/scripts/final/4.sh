function isnum(){

	echo "$1" | grep -E "^\-?[0-9]+$" > /dev/null

	if [ $? -eq 0 ]
	then
		return 0;
	fi


	echo "$1" | grep -E "^\-?[0-9]*\.[0-9]+$" > /dev/null

	if [ $? -eq 0 ]
	then
		return 0;
	fi

	echo "Error: Input not a number"
	exit 1
}
	

if [ $# -ne 3 ]
then
	echo "Error: Invalid Number of Arguments!"
	exit 1
fi


a="$1"
b="$2"
c="$3"

isnum "$a"
isnum "$b"
isnum "$c"



b2=`echo " $b * $b " | bc`
	
	
	ac=`echo " 4 * $a * $c" | bc`
	



	b24ac=`echo " $b2 - $ac "| bc` 


	if [  `echo " $b24ac < 0" | bc` -eq 0 ]
	then

		desc=`echo "sqrt($b24ac)" | bc`
		
	
		root1=`echo "scale=5;( - $b  + $desc ) / 2 * $a" | bc`
	
		root2=`echo "scale=5;( - $b  - $desc ) / 2 * $a" | bc`
		
		
		echo "$root1,$root2"

	else
		echo "No Solutions were found"
		exit 1
	fi

