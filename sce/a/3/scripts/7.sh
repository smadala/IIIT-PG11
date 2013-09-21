#stat /etc/UPower/UPower.conf -c'%X'
#date -d @1379599254 +"%b %d %H:%M"
if [ $# -ne 0 ]
then 
        echo "Error: Invalid Number of Arguments!" >&2
        exit 1
fi 
acc=`sudo find /etc -type f -daystart -atime 1`
'rm' AccessLog 2> /dev/null
IFS=$'\n'
for line in $acc
do
	epoch=`sudo stat "$line" -c'%X'`
	time=`date -d @$epoch +"%b %d %H:%M"`
#	echo $time
	echo -e "$line\t$time"  >> AccessLog
done 
