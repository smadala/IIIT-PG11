#get line by line from file
for cmd in `cat commandlist`
do
	man $cmd >> helper.txt

done
