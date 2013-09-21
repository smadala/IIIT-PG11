echo  "enter a name:\c"
read fname
if [ -s $fname ]
then
echo "file"
else 
echo "not file"
fi
