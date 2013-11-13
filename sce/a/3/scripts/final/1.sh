if [ $# -ne 0 ]
then
	echo "Error: InvalId Number of Arguments!"
	exit 1
fi

IFS=' '
content=`cat $0`
len=${#content}
len=`expr $len - 1`
while [ $len -ne -1 ]
do
result=$result${content:len:1}

((len--))
	
done
echo $result
