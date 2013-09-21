#content=`cat < $0`
#echo $content
content=`cat $0`
IFS=$EOF
len=${#content}
len=`expr $len - 1`
while [ $len -ne -1 ]
do
	
result=$result${content:len:1}
((len--))
	
done
echo $result



