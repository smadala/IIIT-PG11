#date -d @1379599254 +"%b %d %H:%M"
#stat /etc/UPower/UPower.conf -c'%X'
if [ $# -ne 0 ]
then
	echo "Error: Invalid Number of Arguments!" >&2
	exit
fi
acc=`sudo find /etc -daystart -atime 1 -print0`
'rm' AccessLog 2> /dev/null
while IFS= read -r -d '' n
do
	epoch=`stat "$line" -c'%X'`
	time=`date -d @$epoch +"%b %d %H:%M"`
#	echo $time
	echo -e "$line\t$time"  >> AccessLog
done < <($acc)
	
