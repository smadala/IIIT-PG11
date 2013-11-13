t=10
rm 22.in 2> /dev/null
echo $t >> 22.in
for ((i=0;i<t;i++))
do	
	n=$(( $RANDOM % 10000 + 1 ))
	echo $n >> 22.in
	for((j=0;j<n;j++))
	do
		echo $(($RANDOM * $RANDOM * $RANDOM % (10**12) )) >> 22.in
	done
done

	
