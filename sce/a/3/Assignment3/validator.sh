#!/bin/bash 

reset=$(tput sgr0)
txtbld=$(tput bold)
bldred=${txtbld}$(tput setaf 1)
bldyellow=${txtbld}$(tput setaf 3)
bldgreen=${txtbld}$(tput setaf 2)

if [ $# -ne 2 ];then echo "${bldyellow}Usage: $0 ${bldred}<RollNumber> ${bldgreen}<File to be uploaded (in .tar.gz)>${reset}";exit 1;fi

rollnumber=$1
inputfile=$2

validfilename="${rollnumber}_Assignment3.tar.gz"

if [ ! "$inputfile" == "$validfilename" ]
then
	echo "${bldred}ERROR: Your filename is invalid. Please change it to $validfilename ${reset}"
	exit 1
fi

if [ ! -f "$inputfile" ]
then
	echo "${bldred}ERROR: The specified .tar.gz file doesn't exist!. Copy it to this directory and try again! ${reset}"
	exit 1
fi

mkdir TEST
tar -xzf "$inputfile" -C ./TEST/ 2>/dev/null 1>/dev/null

if [ $? -ne 0 ]
then
	echo "${bldred}ERROR: Your Sumbission is not in GZIP format. Please create a .tar.gz again ${reset}"
	rmdir TEST
	exit 1
fi

ValidDirName="${rollnumber}_Assignment3"
cd TEST

if [ ! -d $ValidDirName ]
then
	echo "${bldred}ERROR: You did not create a directory $ValidDirName in your .tar.gz. Please create this first, put in all your answers and then compress ${reset}"
	rm -rf *
	cd ..
	rmdir TEST
	exit 1
fi 
 
cd $ValidDirName

touch attempts

for i in 1.sh 2.sh 3.sh 4.sh 5.sh 6.sh 7.sh 7Extra 8.sh 8Extra.sh 9a.sh 9b.sh 10.sh
do
	if [ -f $i ]
	then
		echo $i >> attempts
	fi
done

flag=0
count=11

for i in 11.sh 12.sh 13.sh 14.sh
do
	if [ -f $i ]
	then
		echo "${bldyellow}INFO: You have attempted Domain question $count. Make sure it is in your domain if you are a MTech Student ${reset}"
		if [ 1 -eq $flag ];then echo "${bldred}ERROR: You have attempted more than 1 domain question. Keep only one and try again ${reset}";cd ../..;rm -rf TEST;exit 1;fi
		flag=1
		echo $i >>attempts
	fi
	count=$(($count+1))
done

ATTEMPTS=`wc -l attempts | cut -d' ' -f1`
ATTEMPTS_IN_DIR=`ls | wc -l`
ATTEMPTS_IN_DIR=$(($ATTEMPTS_IN_DIR-1)) #dont include attempts file


if [ $ATTEMPTS -ne $ATTEMPTS_IN_DIR ]
then
	echo "${bldred}ERROR: You have stray files in your directory. Make sure you remove all hidden files (Press Ctrl+H to show hidden files)${reset}"
	echo "${bldyellow}Only files 1.sh 2.sh 3.sh 4.sh 5.sh 6.sh 7.sh 7Extra 8.sh 8Extra.sh 9a.sh 9b.sh 10.sh and any one of 11/12/13/14.sh can exist here${reset}"
	cd ../..;rm -rf TEST;
	exit 1
fi

rm attempts

for file in *
do
	echo $file | grep "^[0-9]\.sh$" &>/dev/null
	
	if [ $? -ne 0 ]
	then
		case $file in
		7Extra);;
		8Extra.sh);;
		11.sh);;
		12.sh);;
		13.sh);;
		14.sh);;
		*)echo "${bldred}ERROR: You have a stray file $file!. You can't try to be too smart here! You must have only the approved files!'${reset}";cd ../..;rm -rf TEST;exit 1;;
		esac
	fi
done

echo -e "${bldgreen}SUCCESS: Yes! Your files are in the proper format!. Upload your tar.gz to the upload portal!${reset}\n${bldyellow}PS:We cannot validate your messages though!${reset}"
cd ../..;rm -rf TEST;
exit 0		
		

