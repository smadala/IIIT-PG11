#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#define BUFF_SIZE 3

void reverse(char *,char *,int ,int);
int getchar1(int);
void reverseBuffer(char *,int , int );


void main()
{
	int fd_R,fd_W;                                          //read, write file descriptor
	int errno;
	char fileName_R[20]="data.txt";					//array for reading file
	char fileName_W[20]="rev_data.txt";					//array for writing file
	char option;


	printf("Please enter the file name to be read:\t");
//	scanf("%s",fileName_R);

	fd_R=open(fileName_R,O_RDONLY|O_CREAT,0);

	printf("Please enter the file name to be write:\t");	
//	scanf("%s",fileName_W);

	fd_W=open(fileName_W,O_WRONLY|O_CREAT,0);
	
	if(fd_R==-1 || fd_W==-1)
		printf("file openning fail with error %s\n",strerror(errno));
	else
	{
		reverse(fileName_R,fileName_W,fd_R,fd_W);
		printf("CONGRATS! reversal done\n");
	}

}
	
void reverse(char *fnameptr_R,char *fnameptr_W,int fd_R,int fd_W)
{ 
	char *buffer;                               
	int i,sizeRead;
		
	struct stat st;
	stat(fnameptr_R,&st);
	int fileSize =st.st_size;

	printf("size of %s is: %d\n",fnameptr_R,fileSize);    
		
	chmod(fnameptr_W, S_IRWXU);
		
	buffer = (char *)malloc(sizeof(char)*BUFF_SIZE);
		
		
	for( i = 1; fileSize>0; i++)
	{
		lseek(fd_R,-i*BUFF_SIZE,SEEK_END);
		sizeRead = read(fd_R,buffer,BUFF_SIZE);
		reverseBuffer( buffer, fd_W, sizeRead);
		fileSize -=BUFF_SIZE;
		printf("%d iteration\n",i);
	}
	
}

void reverseBuffer(char *ptr,int des, int sizeRead)
{
	int i;
	char *buffer;
	
	buffer = (char *)malloc(sizeof(char)*BUFF_SIZE);	
			
	for( i=sizeRead; i>=0; i--)
		buffer[sizeRead-i-1] = ptr[i];

	write(des, buffer, sizeRead);
}

