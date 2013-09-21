#include<stdio.h>
#include<stdlib.h>
#include "reversefile.h"

/**
Programmer: Madala V V Satyanarayana
Roll no: 201305508
Date: 8th Aug 2013
*/
 
int main(int argc,char * argv[]){
if(argc!=2){
printf("Please enter file name which content to be reversed\n");
exit(1);
}
return reverseFileContent(argv[1]);
}
