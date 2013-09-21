echo "file name?:\c"
read f

terminal=`tty`

exec < $f
l=0
w=0
while read line
do
	l=`expr $l + 1`
	set $line
	w=`expr $w + $#`
done

echo "w = $w"
echo "l= $l"

exec < $terminal

