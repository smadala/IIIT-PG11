#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;
int main(int argc,char* argv[]){
   /* struct dirent **namelist;
    struct stat *buf=NULL;
    char f_name[200];*/
    int c;
    vector<string> options;
    vector<string> files;

    c=argc;

    if(argc != 1 ){
     c--;
     while(c>0){
     if(argv[c][0]=='-')
     options.push_back(argv[c]+1);
     else
     files.push_back(argv[c]);
     c--;
    }
 }
   if(files.size()==0) files.push_back(".");
string s("");   //init(files,options)
reverse(options.begin(),options.end());
for(vector<string>::iterator it=options.begin();it!=options.end();++it){
cout<< *it << endl;
s+=*it;
}
s = tostring(42);
cout<<s<<endl;
return 0;
}

