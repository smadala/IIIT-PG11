#content=`cat < $0`
#echo $content
#oldIFS=$IFS
if [ $# -ne 0 ]
then
	echo "Error: InvalId Number of Arguments!" >&2 
	exit 1
fi

IFS=' '
content=`cat $0`
len=${#content}
len=`expr $len - 1`
while [ $len -ne -1 ]
do
result=$result${content:len:1}
#result=${content:len:1}

#echo -ne "$result"
((len--))
	
done
echo $result
#export IFS=$oldIFS
