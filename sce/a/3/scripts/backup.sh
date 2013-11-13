IFS=' '
if [ $# -ne 0 ]
then
	echo "Error: Invalid Number of Arguments!" >&2
	exit
fi

'rm' backup.sh 2>/dev/null

while read line
do
	echo $line >> backup.sh
done < $0

