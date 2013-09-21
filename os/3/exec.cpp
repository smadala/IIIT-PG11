#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	char** a;
	a=(char **) calloc(3,sizeof(char*));
	for(int i=0;i<3;i++)
	{
		a[i]=(char *)malloc(10);
	}
	a[0]="echo";
	a[1]=".";
	a[2]=NULL;
/*	int *status;
	pid_t cid = fork();
        if(cid==0)
	     execvp(*a,a);
	else 
		while(wait(status) != cid);*/
    execvp(*a,a);
    return 0;
}
