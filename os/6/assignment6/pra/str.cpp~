#include<iostream>
#include<string.h>
#include<string>
#include<libgen.h>
#include<stdio.h>
using namespace std;
int main(){
	char *path="/root/1/2/3/4/5/filename";
//	char *path1="/root/1/2/3/4/5/filename";
//	char *fname=basename(path);
//	char *dname=dirname(path);
	//cout<<path<<"  "<<path1<<endl;
//	cout<</*basename(path)<<*/"  "<<dirname("/root/veen") <<endl;
/*	char *out=basename("root1/kira/l");
	printf("%s",out);*/
	char *dirc, *basec, *bname, *dname;
          // char *path = "/etc/passwd";

        dirc = strdup(path);
        basec = strdup(path);
        dname = dirname(dirc);
        bname = basename(basec);
       // printf("dirname=%s, basename=%s\n", dname, bname);


	char *cur=strtok(dname,"/");
	while( cur != NULL)
	{
		cout<<cur<<endl;
		cur=strtok(NULL,"/");
	}
	cout<<bname<<endl;
}
