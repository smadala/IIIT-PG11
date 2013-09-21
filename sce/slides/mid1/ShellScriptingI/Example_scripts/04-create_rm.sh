#!/bin/bash

echo "#!/bin/rm" > 04-rm.sh
echo "You wont find this file later" >> 04-rm.sh

chmod +x 04-rm.sh

echo "Going to do ls to show 04-rm.sh file"
echo
ls
echo
echo "Notice 04-rm.sh file exists and press enter"


echo
echo "Contents of 04-rm.sh are"
more 04-rm.sh
echo

echo "Execute 04-rm.sh and then do less again"

exit 0 

