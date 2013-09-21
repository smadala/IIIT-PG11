#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include "yshell.h"
using namespace::std;
void parsecmd(string cmd, char** argv){
	char *temp;
        temp=(char*)calloc((cmd.length()+1),sizeof(char*));
	cmd.copy(temp,cmd.length(),0); // convert string to char*
//	argv=(char**)malloc(10*sizeof(char*));
	for(int i=0;i<10;i++){
		argv[i]=(char*)malloc(50*sizeof(char*)); //todo 3
	}
	int i=0;
	while(*temp){
		while(*temp == ' ' ||
				*temp == '\t'||
				*temp == '\n'){ // until space ,tab or newline
			*temp ='\0';
			temp++;
		}
		if(*temp == '\0') { //is last string
			temp++;
			continue;
		}
		argv[i++]=temp; //assgin start address
		while(*temp != '\0' && 
				*temp != '\t' &&
				*temp != '\n' &&
				*temp != ' ' )// other than space, tab, newline or null pass 
		{        
			if(*temp == '$') { 
				char* value=getenv(temp+1);
				argv[i-1]=value;
			}
		/*	else if(*temp == '>'){
				if( *(temp+1) != '>'){ //!= >>
					if( *(temp-1) == '\0'){// ls >1.txt a[0]=ls a[1]= ">" a[2] = 1.txt
						argv[i++]=">";
						*temp='\0';
						if(*(temp+1) != ' ') 
						argv[i++]=++temp;
					}else{// ls>1.txt a[0]=ls a[1]=">" a[2]= 1.txt
						*temp='\0';
						argv[i++]=">";
						argv[i++]=++temp;*/
			temp++;
		}
	argv[i]=NULL; //last parameter should be NULL for execvp
	}
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
        	a=(char**)malloc(10*sizeof(char*));//todo 3
		parsecmd(all[i],a);
		final.push_back(a);
	}
	return final;
}

/*int main(){
//        vector<char**> final=parseCommand("ls -l .. | wc -l  | wc -lm");
        vector<char**> final=parseCommand("        ps   |  wc    -al lll   | ls");
	
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
