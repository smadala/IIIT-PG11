#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include "reversefile.h"

/**
Programmer: Madala V V Satyanarayana
Roll no: 201305508
Date: 8th Aug 2013
*/

/**
return: reverse of given string
*/

char* strrev(char *orginal) {
  long long len=0,i;
  char *reverse;
 //find legnth of string
  while(*orginal){
      orginal++;
      len++;
  }
  reverse=malloc(len+1);
  
 //copy from last character
  for(i = 0; i < len ;i++){
       *(reverse+i)=*(--orginal);
  }
  return reverse;
}

/** return: buffer size based on file size
if less than MIN_BUFFER then returns file size
if less than 10 times of MIN_BUFFER then return MIN_BUFFER
otherwise returns min of MAX_BUFFER and fileSize/10
*/

off_t getBufferSize(off_t fileSize){
  off_t chunckSize;

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

/**
caluclate file size
caluclate buffer size based on filesize
start reading from src file as chuncks of bytes of size buffer size
reverse the chunck data and write to dest file
last chunck size may be less than buffer size then read remaining bytes, reverse and write
*/

void reverseFile(int srcFileDesc,int destFileDesc){
char *buffer;
off_t left=0;// number of bytes 
off_t bufferSize,fileSize,end;
// get file size
fileSize=lseek(srcFileDesc,0,SEEK_END);
//get appropriate buffer size
bufferSize=getBufferSize(fileSize);

printf("buffer size:%lld\n", (long long)bufferSize);

buffer=malloc(bufferSize);

end=lseek(srcFileDesc,-bufferSize,SEEK_END);

while(read(srcFileDesc,buffer,bufferSize) > 0){
buffer=strrev(buffer);
write(destFileDesc,buffer,bufferSize);
end=end-bufferSize>0?end-bufferSize:(left=end-bufferSize)?0:0;
//bufferSize divides fileSize 
if(left ==-bufferSize)
break;
//write last chunck
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
int srcFileDesc;
int destFileDesc;
//get reversed file name
reversedFileName=getReversedFileName(orginalFileName);
 if((srcFileDesc=open(orginalFileName,O_RDONLY)) < 0){
       printf("unable to read file: %s\n", orginalFileName);
       exit(1);
}

 if((destFileDesc=open(reversedFileName,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR)) < 0){
      printf("unable to create or write to file: %s\n",reversedFileName);
      exit(1);
}

reverseFile(srcFileDesc,destFileDesc);
return 0;
}
