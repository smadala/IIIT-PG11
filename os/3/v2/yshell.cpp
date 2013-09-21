#include<iostream>
#include<string.h>
#include<sys/wait.h>
#include<vector>
#include<stdio.h>
#include<unistd.h>
#include<string>
#include<stdlib.h>
#include "yshell.h"
#define SHELL_NAME "YShell"
#define WEL_MSG  "----------Welcome to YShell-----------"

using namespace::std;
/*void parsecmd(string cmd, char** argv){
	char *temp;
        temp=(char*)malloc((cmd.length()+1)*sizeof(char*));
	cmd.copy(temp,cmd.length(),0);
	//argv=(char**)malloc(10*sizeof(char*));
	for(int i=0;i<10;i++){
		argv[i]=(char*)malloc(50*sizeof(char*));
	}
	int i=0;
	while(*temp){
		while(*temp == ' ' ||
				*temp == '\t'||
				*temp == '\n'){
			*temp ='\0';
			temp++;
		}
		argv[i++]=temp;
		while(*temp != '\0' && 
				*temp != '\t' &&
				*temp != '\n' &&
				*temp != ' ' )
			temp++;

	}
	argv[i]=NULL;*/
/*	argv[0]="ls";
	argv[1]=NULL;
	execvp(*argv,argv);*/
	void exec(char **argv){
        pid_t cid;
	cid=fork();
	if(cid < 0){
	        perror("forking child process failed \n");
                return;
	}else if(cid == 0){
		if( execvp(*argv,argv) < 0 )
			 perror("ERROR in execvp: ");
	}else{
		int status;
		while(wait(&status) != cid);
	}
}
void process(char **argv){
        pid_t cid;
	cid=fork();
	if(cid < 0){
		cerr<<"forking child process failed "<<endl;
                return;
	}else if(cid == 0){
		if(strcmp(*argv,"exit")==0) return;//terminate program 
		if( execvp(*argv,argv) < 0 )
			 perror("ERROR in execvp: ");
	}else{
		int status;
		while(wait(&status) != cid);
	}
}
void init(){
//	string cwd;
char *cd;
//char *argv[10];
string input;
vector<char**> cmds;
string exit("exit");
while(1){
	cd=get_current_dir_name();
	cout<<SHELL_NAME<<":"<<cd<<"$ ";
	getline(cin,input);
	if(exit.compare(input) == 0) return;
        
        cmds = parseCommand(input);
	exec(cmds[0]);
//	input=NULL;
//	process(argv);
//	cout<<endl;
}
//cd=malloc(250*sizeof(char));
}

int main(){
cout<<endl<<WEL_MSG<<endl<<endl;
init();
return 0;
}
