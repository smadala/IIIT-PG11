echo "enter a char: \c"
read c
case $c in
[a-z])
	echo " lower"
	;;
[A-Z]) 
	echo "upper"
	;;
[0-9])
	echo " digit"
	;;
?)	
	echo "special"
	;;
*)
	echo "string"
	;;
esac

