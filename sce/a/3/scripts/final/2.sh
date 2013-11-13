IFS=' '
if [ $# -ne 0 ]
then
	echo "Error: Invalid Number of Arguments!"
	exit 1
fi

'rm' backup.sh 2>/dev/null

while read line
do
	echo $line >> backup.sh
done < $0

