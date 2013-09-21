
if [ $# -ne 0 ]
then
	echo "Error: Invalid Number of Arguments!" >&2
	exit
fi
$new="\n"
while read line
do
	
	content=$content$line
	content=$content$new
done < $0

echo -e $content



