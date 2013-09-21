echo " enter a characte:\c"
read s
if [ `echo $s | wc -c` -eq 2 ]
then
 echo "one char"
else
	echo "invalid"
fi
