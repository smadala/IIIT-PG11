echo "Enter a word:\c"
read w
case $w in
[aeiou]* | [AEIOU]*)
	echo "vowel"
	;;
[0-9]*)
	echo "digit"
	;;
# three letter ??? not ...
???)
	echo "three"
	;;
esac
