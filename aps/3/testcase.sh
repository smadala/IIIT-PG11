num=1000000
'rm' sequence.txt 2>/dev/null
echo $num >> sequence.txt
for ((i=0;i<$num;i++))
do
	echo $i >> sequence.txt
done

./a.out < sequence.txt > output.txt

	
