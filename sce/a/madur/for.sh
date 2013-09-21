# * means all files in current dir
for item in *
do
	if [ -d $item ]
	then
 		echo $item
	fi
done
