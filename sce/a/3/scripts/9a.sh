function strcmp(){
	a="$1"
	b="$2"
	if [ -z "$1" -a -z "$2" ]
	then
		echo "0"
		return
	fi

	i=0

	f=`printf "%d" "'${a:i:1}"`

	s=`printf "%d" "'${b:i:1}"`

	while [ $f -ne 0 -o $s -ne 0 ]
	do
		if [ $f -eq $s ]
		then
		 	((i++))
			f=`printf "%d" "'${a:i:1}"`
			s=`printf "%d" "'${b:i:1}"`
			continue
		fi
			echo `expr $f - $s` 
			return
	done
	echo "0"
}
function strlen(){
	a="$1"

	if [ -z "$1" ]
	then
		echo "0"
		return
	fi

	i=0;
	f=`printf "%d" "'${a:i:1}"`
	while [ $f -ne 0 ]
	do
		((i++))
		f=`printf "%d" "'${a:i:1}"`
	done


	echo "$i"
}


function strcat(){
	echo "$1$2"
}

function strstr(){
	a="$1"
	b="$2"
	i=0
	j=0
	f=`printf "%d" "'${a:i:1}"`
	s=`printf "%d" "'${b:j:1}"`
	while [ $f -ne 0 ]
	do
		if [ $f -eq $s ]
		then
			((j++))
			((i++))	

			s=`printf "%d" "'${b:j:1}"`

			if [ $s -eq 0 ]
			then
				echo `echo "$i - $j"|bc`
				return
			fi
			f=`printf "%d" "'${a:i:1}"`
		else
			j=0;
			s=`printf "%d" "'${b:j:1}"`
			((i++))
			f=`printf "%d" "'${a:i:1}"`
		fi

	done
	echo "-1"
}
	
function strtok(){
	a="$1"
	b="$2"
	if [ -z "$a" ]
	then
			echo
			return
	fi
	i=0

	del=`printf "%d" "'${b:0:1}"`

	f=`printf "%d" "'${a:i:1}"`

	del_len=${#b}
	
	j=0

	for ((i=0;i<del_len;i++))
	do
		del=`printf "%d" "'${b:i:1}"`

		f=`printf "%d" "'${a:j:1}"`

		if [ $f -eq $del ]
		then
			((j++))
			 i=-1
		fi
	done


	start=$j
	end=0

	while [ $f -ne 0 ]
	do
		for ((i=0;i<del_len;i++))
		do
		asc=`printf "%d" "'${b:i:1}"`
		if [ $f -eq $asc ]
		then
			echo "${a:$start:$end}"
			return
		fi
		done
		((end++))
		((j++))
		f=`printf "%d" "'${a:j:1}"`
	done
	
	a_len=${#a}
	end=`expr $a_len - $start`
	echo "${a:$start:$end}"
	return
}


