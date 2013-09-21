echo "Enter a file name:\c"
read f
if [ -z "$f" ]
then
	exit
fi

terminal=`tty`

exec < $f

count=1

while read line
do
	echo $count.$line
	count=`expr $count + 1`
done

exec < $terminal

