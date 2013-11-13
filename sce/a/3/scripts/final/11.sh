function quickUnion(){
	n=0
	while [ $n -ne $1 ]
	do
		a[$n]=$n
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
	a[$re1]=$re2
}

function mysort(){
s="$1"
j=${#s}
j=$(( $j -1 ))
lines=""
for i in ${s[@]}
do
	lines=$lines$i
	if [ $i -ne $j ]
	then
	lines=$lines'\n'
	fi

done
res=`echo -e $lines | sort -g`
echo $res >> CopyGroups
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


((count++))
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
	

	re=`connected ${g[$f]} ${g[$s]}` 

	if [ $re -eq 0 ]
	then
		continue
	else
		union ${g[$f]} ${g[$s]}
	fi
done < "$1"

i=0
out=()
while [ $i -ne $count ]
do
	re=`root $i`	
	out[$re]="${out[$re]}${ind[$i]} "
	((i++))
done


	
'rm' CopyGroups 2> /dev/null

for key in ${!out[@]}
do
	mysort "${out[$key]}"
done

