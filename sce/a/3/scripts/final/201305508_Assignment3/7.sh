if [ $# -ne 0 ]
then 
        echo "Error: Invalid Number of Arguments!"
        exit 1
fi 
acc=`sudo find /etc -type f -daystart -atime 1`
rm AccessLog 2> /dev/null
IFS=$'\n'
for line in $acc
do
	epoch=`sudo stat "$line" -c'%X'`
	time=`date -d @$epoch +"%b %d %H:%M"`
	echo -e "$line        $time"  >> AccessLog
done 
