#s="201205874 201305641 201305581 201305051 201305021"
#s=(201305641 201305581 201305051 201305021 201205874)
s="201305641 201305581 201305051 201305021 201205874"
a=()

j=${#s}
j=$(( $j -1 ))
for i in ${s[@]}
do
	lines=$lines$i
	if [ $i -ne $j ]
	then
	lines=$lines'\n'
	fi

done
res=`echo -e $lines | sort -g`
echo $res


#for ((k=0;k<j;k++))
#do
#	for((l=k+1;l>0;l--))
#	do
#		p=$(($l -1 ))
#		if [ ${a[$l]} -lt ${a[$p]} ]
#		then
##			echo "${a[$l]} < ${a[$p]}"
#			temp=${a[$l]}
#			a[$l]=${a[$p]}
#			a[$p]=$temp
#		else
#			break
#		fi
#	done
#done
#
##for i in ${a[@]}
##do
##	echo "$i"
##done
