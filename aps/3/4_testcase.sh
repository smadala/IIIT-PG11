n=1000
maxLength=20
a=()
'rm' 4_in.txt 2> /dev/null
for ((i=0;i<26;i++))
do
	a[$i]=$(($i+1));
done
for ((i=0;i<1000;i++))
do
	 s=""
	 len=`expr $RANDOM % 20`
	 len=`expr $len+1`
	 for (( j=0;j<$len;j++ ))
	 do	
	 	r=`expr $RANDOM % 26`
	 	s="$s${a[$r]}"
	 done
	 echo "$s" >> 4_in.txt
done

echo "0" >> 4_in.txt

	 	
	
