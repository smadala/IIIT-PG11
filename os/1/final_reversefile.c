#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include "reversefile.h"

/**
Programmer:Madala V V Satyanarayana
Roll no:201305508
Date:8th Aug 2013
*/

/**
return: reverse of given string
*/
char* strrev(char *orginal) {
  long len=0,i;
  char *reverse;
 //find legnth of string
  while(*orginal){
      orginal++;
      len++;
  }
  reverse=malloc((len+1)*sizeof(char));
  
 //copy from last character
  for(i = 0; i < len ;i++){
       *(reverse+i)=*(--orginal);
  }
  return reverse;
}
/**
*/
long getBufferSize(long fileSize){
long chunckSize;
if(fileSize < MIN_BUFFER)
return fileSize;
else if(fileSize <= 10*MIN_BUFFER)
return MIN_BUFFER;
else{
chunckSize=fileSize/10;
if(chunckSize > MAX_BUFFER)
return MAX_BUFFER;
return chunckSize;
}
}
void reverseFile(int srcFileDesc,int destFileDesc){
char *buffer;
long left=0;
long bufferSize,fileSize,end;
fileSize=lseek(srcFileDesc,0,SEEK_END);
bufferSize=getBufferSize(fileSize);
buffer=malloc(bufferSize);

end=lseek(srcFileDesc,-bufferSize,SEEK_END);
while(read(srcFileDesc,buffer,bufferSize) > 0){
buffer=strrev(buffer);
write(destFileDesc,buffer,bufferSize);
end=end-bufferSize>0?end-bufferSize:(left=end-bufferSize)?0:0;
if(left ==-bufferSize)
break;
if(end==0 ){
memset(buffer, '\0', sizeof(buffer));
lseek(srcFileDesc,end,SEEK_SET);
read(srcFileDesc,buffer,bufferSize+left);
buffer=strrev(buffer);
write(destFileDesc,buffer,bufferSize+left);
break;
}
lseek(srcFileDesc,end,SEEK_SET);
}
close(srcFileDesc);
close(destFileDesc);
free(buffer);
}

char* getReversedFileName(char* orginalFileName){
char *reversedFileName;
reversedFileName=malloc(MAX_FILE_NAME_LENGTH);
strcat(reversedFileName,REVERSED_FILE_PREFIX);
strcat(reversedFileName,orginalFileName);
return reversedFileName;
}

int reverseFileContent( char *orginalFileName){

char *reversedFileName;
reversedFileName=getReversedFileName(orginalFileName);
int srcFileDesc=open(orginalFileName,O_RDONLY);
int destFileDesc=open(reversedFileName,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
reverseFile(srcFileDesc,destFileDesc);
return 0;
}



/*int main(int argc,char* argv[]){
if(argc!=2){
printf("Please enter file name which content to be reversed\n");
exit(1);
}
return reverseFileContent(argv[1]);
}*/





