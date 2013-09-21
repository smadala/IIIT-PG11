#!/bin/bash

echo "enter 1st date (MM/DD/YYYY)"
read fr
echo "enter 2nd date"
read se
old=`date -d $fr +%s`
new=`date -d $se +%s`
res=$((($new-$old)/(86400)))
echo $res

