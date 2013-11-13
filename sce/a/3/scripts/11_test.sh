function quickUnion(){
	n=0
	while [ $n -ne $1 ]
	do
		a[$n]=$n
		s[$n]=1
		((n++))
	done
}
function root(){
	i=$1
	while [ $i -ne ${a[$i]} ]
	do
		i=${a[$i]}
	done
	echo $i 
}

function connected(){
	re1=`root $1`
	re2=`root $2`
	if [ $re1 -eq $re2 ]
	then
		echo 0
		return
	fi
	echo 1
	return
}
function union(){
	re1=`root $1`
	re2=`root $2`
	if [ ${s[$res1]} -lt ${s[$res2]} ]
	then
		a[$res1]=$res2;
		s[$res2]=$((${s[$res1]}+${s[$res2]}))
	else
		a[$res2]=$res2;
		s[$res1]=$((${s[$res1]}+${s[$res2]}))
	fi
}

if [ $# -ne 1 ]
then
	echo "Error: Invalid Number of Arguments!"
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "Error: Invalid File!"
	exit 1
fi

a=()
s=()
g=()
ind=()
count=-1
while read l
do	
	if [ -z "$l" ]
	then
		continue
	fi
	line=($l)
	f=${line[0]}
	s=${line[1]}
	
	 gf=${g[$f]}
	 gs=${g[$s]}
	
	 if [ -z $gf ]
	 then
		((count++))
	 	g[$f]=$count
		ind[$count]=$f
	 fi

	 if [ -z $gs ]
	 then
		((count++))
	 	g[$s]=$count
		ind[$count]=$s
	 fi

		
	
done < "$1"

#for item in ${!i[@]}
#do
#	echo "$item --> ${i[$item]}"
#done
#for i in ${!g[@]}
#do
#	echo "$i --> ${g[$i]}"
#done

((count++))
#echo "count $count"
quickUnion $count

while read l
do
	if [ -z "$l" ]
	then
		continue
	fi
	line=($l)
	f=${line[0]}
	s=${line[1]}
	
#echo "$f --> $s"

	re=`connected ${g[$f]} ${g[$s]}` 

	if [ $re -eq 0 ]
	then
#		echo "connected"
		continue
	else
#		echo "not conn"
		union ${g[$f]} ${g[$s]}
	fi
done < "$1"

i=0
out=()
while [ $i -ne $count ]
do
	re=`root $i`	
#echo "$re"
	out[$re]="${out[$re]}${ind[$i]} "
	((i++))
done


	
'rm' CopyGroups 2> /dev/null

for key in ${!out[@]}
do
	echo "${out[$key]}" | cat >> CopyGroups
done

