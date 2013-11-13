if [ $# -ne 2 ]
then
	echo "Error: Invalid Number of Arguments!"
	exit 1
fi
. ./9a.sh
IFS=$'\n'

                    
echo `strcmp $1 $2`

echo `strlen $1`

echo `strlen $2`

echo `strcat $1 $2`

echo `strtok $1 $2`

echo `strstr $1 $2`
