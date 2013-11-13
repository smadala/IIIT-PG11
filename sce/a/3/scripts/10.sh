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

'rm' PasswordTest 2> /dev/null

IFS=$'\n'
weak="WEAK"
strg="STRONG"
while read line
do
	len=${#line}
	if [ $len -lt 8 ]
	then
		echo $weak | cat  >> PasswordTest
		continue
	fi
	
	sp=0
	nu=0

	for ((i=0;i<len;i++))
        do  
                f="'${line:i:1}"
                num=`printf "%d" "'${line:i:1}"`
                if [ $num -ge 48 -a $num -le 57 ]
                then
                        nu=1
			break
                fi  
        done

	if [ $nu -eq 0 ]
	then
		echo $weak | cat  >> PasswordTest
		continue
	fi
	

	for ((i=0;i<len;i++))
	do
		f="${line:i:1}"
			
		if [ $f = "@" -o   $f = "#" -o $f = "$" -o $f = "%" -o $f = "&" -o $f = "*" -o $f = "+" -o $f = "-" -o $f = "=" ] 
		then
			sp=1
			break
		fi
	done

	if [ $sp -eq 0 ]
	then
		echo $weak | cat  >> PasswordTest
		continue
	fi
	
	dict=0
	i=0
	lower=`echo $line|tr A-Z a-z`
	word_len=3

	while [ $word_len -lt $len ]
	do 
	temp=0
		j=0
		((word_len++))
	for ((i=0;$(($i+$word_len-1))<$len;))
	do
		asc=`printf "%d" "'${lower:$j:1}"`
		if [ $asc -ge 97 -a $asc -le 122 ]
		then

			((temp++))
			((j++))
		else
			i=$(($i+ 1))
			temp=0
			j=$i
		fi

		if [ $temp -eq $word_len ]
		then
			break
		fi
		
	done

	if [ $temp -ne $word_len ]
	then
		((word_len++))
		continue
	fi
	
	
			
	start=$(($i))
	
		echo "${lower:start:word_len}"


	while [ $(($i+$word_len-1)) -lt $len ]
	do
		echo "i-$i wl-$word_len temp-$temp asc-$asc"	
		sub=${lower:i:word_len}
		echo "$sub"	
		grep -E  "^$sub$" /usr/share/dict/words > /dev/null
		if [ $? -eq 0 ]
		then
			echo $sub
			dict=1
			break
		fi
		

		temp=0
		j=0
		for ((;$(($i+$word_len-2))<$len;))
		do
			asc=`printf "%d" "'${lower:$j:1}"`
			if [ $asc -ge 97 -a $asc -le 122 ]
			then
				((temp++))
				((j++))
			else
				((i++))
				temp=0
				j=$i
			fi


			if [ $temp -eq $word_len ]
			then
				break
			fi
			
		done

		if [ $temp -ne $word_len ]
		then
			break
		fi
		

	done

	
			
		if [ $dict -eq 1 ]
		then
			
			echo $weak | cat  >> PasswordTest
			break
		fi
		i=0

	done
	if [ $dict -eq 1 ]
	then
		continue
	fi

	 echo $strg | cat  >> PasswordTest
	
done < "$1"
