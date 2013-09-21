echo "user name:\c"
read u
line=`grep $u /etc/passwd`
IFS=:
set $line
echo "User_name:$1"
echo "user_id:$3"
echo "Group_id:$4"
echo "comment field:$5"
echo "Home_folder:$6"
echo "Default_shell:$7"

