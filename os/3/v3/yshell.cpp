#include<iostream>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<vector>
#include<stdio.h>
#include<unistd.h>
#include<string>
#include<stdlib.h>
#include "yshell.h"
#define SHELL_NAME "YShell"
#define SO 1
#define SI 0
#define WEL_MSG  "----------Welcome to YShell-----------"

vector<string> history;
unsigned int numHistory;

using namespace::std;

int inBuiltCmd(char *cmd){
	if(strcmp(cmd,"cd") == 0)
		return 1;
	else if(strcmp(cmd,"export") == 0)
		return 2;
	else if(strcmp(cmd,"history") == 0)
		return 3;
	else if(cmd[0] == '!')
		return 4;
	else if(strcmp(cmd, "exit") == 0)
		return 5;
	else
		return -1;
}

int handleBuiltIn(char **argv,int inBuilt){
	switch(inBuilt){
		case 1: return cd(argv);

		case 2: return exp(argv);

		case 3: return displayHistory();

		case 4: return execHistory(atoi(argv[0]+1));
	}
}
void pipeHandling(int *fd,int i,int cmdsSize){
		if(i != cmdsSize-1 ){
			dup2(fd[2*i+1],SO);
			if(i!=0)
				dup2(fd[2*(i-1)],SI);
		}else if(i!=0){

			dup2(fd[2*(i-1)],SI);
		}
}

int process(vector<char**> cmds){
        pid_t cid;
	int cmdsSize=cmds.size();
	int fd[cmdsSize*2];
	char **argv;
	int inBuilt;
        

	for(int i=0;i<cmds.size();i++){
	
		argv=cmds.at(i);


	if(pipe(fd+(i*2)) < 0){
		perror("ERROR in pipe() ");
		return 0;
	}
        inBuilt=inBuiltCmd(*argv); 
        //inBuilt=-1; 
	if(inBuilt < 0){
	cid=fork();
	}else{
		cid=inBuilt;
	}
	if(cid < 0){
		cerr<<"forking child process failed "<<endl;
                return 0;
	}else if(cid == 0){
		pipeHandling(fd,i,cmdsSize);
		//cout<<"child: "<< i <<endl;
		//close(fd[0]);
		//close(fd[1]);
		//if(strcmp(*argv,"exit")==0) return;//terminate program 
		cout<<"exec "<< i << *argv<<endl;
		if( execvp(*argv,argv) < 0 )
			 cerr<< *argv <<" : command not found"<<endl;
	}else{
		if(inBuilt < 0){
		int status;
		while(wait(&status) != cid);
		//cout<<"parent:"<< i <<endl;
		//close(fd[2*(i-1)]);
		}else{
			pipeHandling(fd,i,cmdsSize);
			if(inBuilt == 5) return -1; //exit
			if(handleBuiltIn(argv,inBuilt) < 0 ) return -1;
		}
		close(fd[2*i+1]);
	   }

	
}
return 0;
}

int processCmd(string input){
	vector<char**> cmds;
        cmds = parseCommand(input);
	return process(cmds);
}
void init(){
//	string cwd;
char *cd;
//char *argv[10];
string input;
vector<char**> cmds;
vector<int*> pipes;
string exit("exit");


while(1){
	cd=get_current_dir_name();
	cout<<SHELL_NAME<<":"<<cd<<"$ ";
	getline(cin,input);
	history.push_back(input);

	if(exit.compare(input) == 0) return;
       if ( processCmd(input) < 0) return; 
}
}

int main(){
cout<<endl<<WEL_MSG<<endl<<endl;
// load history
importRC();
unsigned int numHistory = loadHistory();
init();
dumpHistory(numHistory);
return 0;
}
