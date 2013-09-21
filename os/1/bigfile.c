#include<stdio.h>
#include<fcntl.h>

int main(){
int srcDesc;
off_t size=524288000,i;
char buffer[]="1234567890123456789012345678901234567890123456789012345678901234567890";
srcDesc=open("500MB.txt",O_CREAT|O_WRONLY,0660);
for(i=0;i<=size;i+=70){
write(srcDesc,buffer,70);
}
return 0;
}
