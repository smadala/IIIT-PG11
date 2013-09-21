#include<iostream>
#include<fstream>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include "yshell.h"

/*void cd(char **a){
	char g[2][10];
	g[0]="ls";
	g[1]=NULL;
	chdir(a[1]);
	execvp("ls",g);
}*/

using namespace std;
//extern vector<string> history;
int cd(char **argv){

/*//------Test--------
   char **a;
a=(char **)malloc(2*sizeof(char*));
for(int i=0; i<2; i++)
	a[i]=(char *) malloc(5*sizeof(char));
a[0]="ls";
a[1]=NULL;*/
if( argv[1] == NULL || argv[1] == "~" ){
	chdir(getenv("HOME"));
}
else
chdir(argv[1]);
//execvp(*a,a);
return 0;
}
int findEqual(char *arg,char **values){
//	values=(char **)calloc(2,sizeof(char *));

	for(int i=0;i<2;i++)
		values[i]=(char*)calloc(50,sizeof(char));
	bool isEq=false;
		values[0]=arg;
		while(*arg != '=' && *arg != '\0'){
			arg++;
		}
		if(*arg == '='){
			isEq=true;
			*arg='\0';
			arg++;
		}
		if(!isEq && *arg == '\0') //no eqaul in key part ex:abbb (or) a =b (or) a = b
			return -1;
		else if( isEq && *arg != '\0'){ // value is also there without space ex: a=b
			values[1]=arg;
			return 0;
		}else if( isEq && *arg == '\0') // if there is space b/w key and value ex: a= b
			return 1;
}

int exp(char **argv){
	int re;
	char *values[2];
	for(int i=1;argv[i]!=NULL;){
		re=findEqual(argv[i],values);
			if(re == -1){
				cerr<<"yshell: export: '"<< argv[i+1] <<"' : not a valid identifier"<<endl;
				return 0;
			}
		       else if(re == 1)
			       values[1]=argv[++i];
	        setenv(values[0],values[1],1);// 1-for overwrite
     //   	cout<<getenv(values[0])<<endl;
		i++;
	}
	return 0;
}
bool isComment(string line){
	char ch;
	for(int i=0; i<line.length();i++){
		ch=line.at(i);
		if(ch == ' ' || ch == '\t' || ch == '\n')
			continue;
		if(ch == '#') //start with '#' is comment
			return true;
		else 
			return false;

	}
	return true;
}
void importRC(){

	char *home = getenv("HOME");
	string h=home;
	h=h+"/.yshellrc";
	//cout<<h<<endl;
	ifstream infile(h.c_str());
	while(getline(infile,h)){
	   if(isComment(h))
		   continue;
	   char *argv[10];//todo 3
	   if( h.find("export ",0) == string::npos){
		   h="export "+h;
	   }
	   parsecmd(h, argv);
	   exp(argv);
	}

}
bool isEnv(char *env){
		if(*env == '$' && *(env+1) != '\0')
			return true;
		return false;
}
int echo(char **argv){
	char *value;
	for(int i=1; NULL!=argv[i]; i++){
		if(isEnv(argv[i])){
		    	if((value=getenv(argv[i])) != NULL)
				cout<<value<<" ";
		}
		else 
			cout<<argv[i]<<" ";
	}
	return 0;
}
void dumpHistory(int numHistory){
	char *home = getenv("HOME");
	string h=home;
	h=h+"/.yshell_history";
	if(history.size() <= 1000){
	ofstream outputFile(h.c_str(),ofstream::app);
		for(int i=numHistory;i<history.size();i++){
	 		outputFile<<history.at(i)<<endl;
		}
		outputFile.close();
	}else{
		ofstream outputFile(h.c_str());
		for(int i=history.size()-1000; i<history.size() ;i++){
			outputFile<<history.at(i)<<endl;
		}
		outputFile.close();
	}
}
int loadHistory(){
        int numHistory=0;
	char *home = getenv("HOME");
	string h=home;
	h=h+"/.yshell_history";
	//cout<<h<<endl;
	ifstream infile(h.c_str());
	while(getline(infile,h)){
		numHistory++;
		history.push_back(h);
	}
	return numHistory;
}
int displayHistory(){
	 for(int i=0;i<history.size();i++){
		 cout<<" "<< i+1 <<" "<<history.at(i)<<endl;
	 }
	 return 0;
 }
int execHistory(int num){
	vector<char**> cmd;
	string line;
//	cout<<num<<endl;

	line=history.at(num-1);
	history.pop_back();
	history.push_back(line);
	return processCmd(line);
}



/*int main( int argc, char **argv){
  // inBuiltCmd(argv[1]);
//	cd(argv);
	exp(argv);
//	importRC();
//	echo(argv);

}*/
