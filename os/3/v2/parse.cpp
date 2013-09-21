#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include "yshell.h"
using namespace::std;
void parsecmd(string cmd, char** argv){
	char *temp;
        temp=(char*)malloc((cmd.length()+1)*sizeof(char*));
	cmd.copy(temp,cmd.length(),0); // convert string to char*
//	argv=(char**)malloc(10*sizeof(char*));
	for(int i=0;i<10;i++){
		argv[i]=(char*)malloc(50*sizeof(char*));
	}
	int i=0;
	while(*temp){
		while(*temp == ' ' ||
				*temp == '\t'||
				*temp == '\n'){ // until space ,tab or newline
			*temp ='\0';
			temp++;
		}
		argv[i++]=temp; //assgin start address
		while(*temp != '\0' && 
				*temp != '\t' &&
				*temp != '\n' &&
				*temp != ' ' )// other than space, tab, newline or null pass 
			temp++;

	}
	argv[i]=NULL; //last parameter should be NULL for execvp
/*	argv[0]="ls";
	argv[1]=NULL;
	execvp(*argv,argv);*/
	
/*        pid_t cid;
	cid=fork();
	if(cid < 0){
		cerr<<"forking child process failed "<<endl;
                return;
	}else if(cid == 0){
		if( execvp(*argv,argv) < 0 )
			 perror("ERROR in execvp: ");
	}else{
		int status;
		while(wait(&status) != cid);
	}*/
}
vector<char**> parseCommand(string cmd){
	vector<string> all; // split by '|' (pipe)
	vector<char**> final;// split by space
	int end,start=0;
	while(1){
		end=cmd.find('|', start);
		if(end==string::npos) { //if no more pipes
			all.push_back(cmd.substr(start, string::npos));
			break;
		}
		all.push_back(cmd.substr(start,end-start));
		start=end+1;// next find start from
	}
	char **a;
	for(unsigned int i=0;i<all.size();i++){
	//	cout<<all[i]<<endl;
        	a=(char**)malloc(10*sizeof(char*));
		parsecmd(all[i],a);
		final.push_back(a);
	}
	return final;
}

/*int main(){
        vector<char**> final=parseCommand("ls -l .. | wc -l  | wc -lm");
	
	char **a;
	for(int i=0;i<final.size();i++){
		a=final[i];
		int j=0;
		while(a[j]!=NULL)
			cout<<a[j++]<<endl;
	}
}*/
/*

void skipSpace(char *temp){
                while(*temp == ' ' ||
                                *temp == '\t'||
                                *temp == '\n'){
                        *temp ='\0';
                        temp++;
		}
}
void parsecmd1(string cmd, char*** argv){
        char *temp;
        temp=(char*)malloc((cmd.length()+1)*sizeof(char*));
        cmd.copy(temp,cmd.length(),0);



        //argv=(char***)malloc(10*sizeof(char**));
        for(int i=0;i<10;i++){
                argv[i]=(char**)malloc(10*sizeof(char*));
		for(int j=0;j<10;j++){
			argv[i][j]=(char *)malloc(50*sizeof(char));
		}
        }

        int i=0;
        while(*temp){
		skipSpace(temp);
		if(*temp == '|'){
			*temp='\0';
			*argv[i]=NULL;
			i=0;
			while(*argv[i] != NULL)
				cout<<*argv[i++]<<endl;
			argv++;
			i=0;
			temp++;
			skipSpace(temp);
		}
                *argv[i++]=temp;
                while(*temp != '\0' &&
                                *temp != '\t' &&
                                *temp != '\n' &&
                                *temp != ' '&&
				*temp != '|')
                        temp++;
        }
        argv[i]=NULL;
}
   */
