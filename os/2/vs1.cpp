#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include <dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<inttypes.h>
#include<vector>
#include<stdlib.h>
//#include<unordered_set>
#include<list>
#include<pwd.h>
#include<grp.h>
#include<algorithm>
#include<iomanip>
#include<sys/ioctl.h>
#define black "\033[1;30m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define brown "\033[1;33m"
#define blue "\033[1;34m"
#define magenta "\033[1;35m"
#define cyan "\033[1;36m"
#define lightgray "\033[1;37m"
#define none "\033[0m"
const char sOpt[] ={'l','R','a','d','S','t'};
using namespace::std;
/*void validateOptions(vector<string>& options){
string opt;
unordered_set<char> sOptions({'l','R','a','d','S','t'});
list<char> gOptions;
char ch;
for(unsigned int i=0;i<options.size();i++){
  opt=options.at(i);
  for(int j=1;i<opt.length();j++){
     ch=opt.at(j);
    if(sOptions.find(ch)!=sOptions.end()){
      	gOptions.remove(ch);
      	gOptions.push_back(ch);
    }else{
   	cerr << "invalid option -- '"<<ch<<"'"<<endl<<"please see README file"<<endl;
   }
  }
 }
cout<<opt<<endl;
}*/
typedef struct file_info{
string perm;
nlink_t hLink;
string uName;
string gName;
blkcnt_t blocks;
off_t size;
time_t time_i;
string time;
string name; 
string fullName;
string color;
string link;
string linkColor;
}f_info;
struct sizeSort{
 inline bool operator() (const f_info& f1,const f_info& f2){
    return(f1.size > f2.size);
  }
};
struct timeSort{
 inline bool operator() (const f_info& f1,const f_info& f2){
    return(f1.time_i > f2.time_i);
  }
};
struct nameSort{
 inline bool operator() (const f_info& f1,const f_info& f2){
  string l=f1.name;
  string r=f2.name;
   transform(l.begin(),l.end(),l.begin(),::tolower);
   transform(r.begin(),r.end(),r.begin(),::tolower);
   return l.compare(r)<0;
  }
};

bool isGiven(string opt,char keyChar){
return  opt.find(keyChar)!=string::npos;
}
bool tIsLatest(string opt){
return opt.find_last_of('t')>opt.find_last_of('S');
}
void getPerm(string& perm, string& link, string& color, string& linkColor,mode_t st_mode,char *path){
link="";
perm="";
linkColor=none;
color=none;
if(S_ISLNK(st_mode))
{
char buf[250];
realpath(path, buf);
string s(buf);
link=" -> "+s;
linkColor=blue;
}
switch (st_mode & S_IFMT)
{
case S_IFLNK: perm+="l"; color=cyan;	break;
case S_IFREG: perm+="-"; break;
case S_IFDIR: perm+="d"; color=blue;	break;
default: perm+="-";
}
switch (st_mode & S_IRWXU)
{
case S_IRUSR: perm+="r--";	break;
case (S_IRUSR|S_IWUSR): perm+="rw-";	break;
case (S_IRUSR|S_IWUSR|S_IXUSR): perm+="rwx";	break;
case (S_IRUSR|S_IXUSR): perm+="r-x";	break;
case (S_IWUSR|S_IXUSR): perm+="-wx";	break;
case (S_IWUSR): perm+="-w-";	break;
case (S_IXUSR): perm+="--x"; break;
default : perm+="---";	break;
}
switch (st_mode & S_IRWXG)
{
case S_IRUSR: perm+="r--";	break;
case (S_IRGRP|S_IWGRP): perm+="rw-";	break;
case (S_IRGRP|S_IWGRP|S_IXGRP): perm+="rwx";	break;
case (S_IRGRP|S_IXGRP): perm+="r-x";	break;
case (S_IWGRP|S_IXGRP): perm+="-wx";	break;
case (S_IWGRP): perm+="-w-";	break;
case (S_IXGRP): perm+="--x"; break;
default : perm+="---";	break;
}
switch (st_mode & S_IRWXO)
{
case S_IROTH: perm+="r--";	break;
case (S_IROTH|S_IWOTH): perm+="rw-";	break;
case (S_IROTH|S_IWOTH|S_IXOTH): perm+="rwx";	break;
case (S_IROTH|S_IXOTH): perm+="r-x";	break;
case (S_IWOTH|S_IXOTH): perm+="-wx";	break;
case (S_IWOTH): perm+="-w-";	break;
case (S_IXOTH): perm+="--x"; break;
default : perm+="---";	break;
}
if(isGiven(perm,'x')&&!isGiven(perm,'d')&&!isGiven(perm,'l')){ /*if(isGiven(perm,'l')) { color=red;linkColor=red;} else*/ color=green;}
}
void getTime(string& time,time_t st_time){
struct tm *t_info=localtime(&st_time);
char *temp=NULL;
temp=asctime(t_info);
for(int i=0;temp[i+4]!='\0';i++)
{
temp[i]=temp[i+4];
}
temp[12]='\0';
time=temp;
}
void getUserAndGroupName(string& uName,string& gName,uid_t uid,gid_t gid){
struct passwd *pwd;
struct group *grp;
if((pwd=getpwuid(uid))==NULL)   uName=""+uid;
else  uName = pwd->pw_name;
if ((grp = getgrgid(gid))== NULL)    gName=""+gid;    
else   gName= grp->gr_name;
}
void getFileInfo(vector<f_info>& detailsV,char* fileName,char* fullPath,struct stat& buf){
f_info details;
//details=(f_info*)malloc(sizeof(f_info));
details.name=fileName;
details.fullName=fullPath;
getPerm(details.perm,details.link,details.color,details.linkColor,buf.st_mode,fullPath);
details.size=buf.st_size;
details.blocks=buf.st_blocks;
details.hLink=buf.st_nlink;
details.time_i=buf.st_mtime;
getTime(details.time,buf.st_mtime);
getUserAndGroupName(details.uName,details.gName,buf.st_uid,buf.st_gid);
detailsV.push_back(details);
}


void process(const char *path,string opt){
struct dirent **namelist;
struct stat buff;
int n;
char *f_name;
char *r_name;
bool ist=isGiven(opt,'t'),isS=isGiven(opt,'S'),isa=isGiven(opt,'a'),isl=isGiven(opt,'l'),isR=isGiven(opt,'R'),isd=isGiven(opt,'d');
vector<f_info> detailsV;
int pathl=strlen(path);
n = scandir(path, &namelist, 0, alphasort);
    
    if (n < 0 || isd ){
        if(lstat(path,&buff)<0){
            perror("lstat");
      }
         else{
              r_name=(char*)calloc(600,(sizeof(char)));
             //find relative file name
              for(int i=0,j=0;path[i]!='\0';i++,j++){
                 r_name[j]=path[i];
                   if(path[i]=='/'){
     		      r_name[0]='\0';
		      j=-1;
		   }
	      }
              f_name = (char*)calloc(600,(sizeof(char)));
              strcat(f_name,path);
              getFileInfo(detailsV,r_name,f_name,buff);
             }
    }
    else {
        while(n--) {
            f_name = (char*)calloc(600,(sizeof(char)));
            strcat(f_name,path);
            if(path[pathl-1]!='/')//don't append / two times
            strcat(f_name,"/");
            if(namelist[n]->d_name[0]=='.' && !isa)
              continue;
             strcat(f_name,namelist[n]->d_name);
             lstat(f_name,&buff);
             getFileInfo(detailsV,namelist[n]->d_name,f_name,buff); 
            /* printf("%zd\n",(intmax_t)buff.st_size);
            printf("%s\t", namelist[n]->d_name);*/
            
}         //   free(namelist[n]);
        }
f_info detail;

// sort output 
if(!(ist||isS))
sort(detailsV.begin(),detailsV.end(),nameSort());
else if(ist&&!isS)
sort(detailsV.begin(),detailsV.end(),timeSort());
else if(!ist&&isS)
sort(detailsV.begin(),detailsV.end(),sizeSort());
else{
  if(tIsLatest(opt)){
    sort(detailsV.begin(),detailsV.end(),sizeSort());
    sort(detailsV.begin(),detailsV.end(),timeSort());
}
  else{
    sort(detailsV.begin(),detailsV.end(),timeSort());
    sort(detailsV.begin(),detailsV.end(),sizeSort());
}
  }

string timeString;
// is long list
if(isl){
int pl=10,dl=13,hl=0,ul=0,gl=0,sl=0,t=0;
off_t x=0;
blkcnt_t bs=0;
nlink_t y=0;
//string hs,ss;
for(vector<f_info>::iterator it=detailsV.begin();it!=detailsV.end();++it){
bs+=it->blocks;
for(x=it->size,t=0; x != 0; x /= 10, t++);
if(t>sl) sl=t;// cout<<st<<endl;}
for(y=it->hLink,t=0; y != 0; y /= 10, t++);
if(t>hl) hl=t;// cout<<st<<endl;}
t=it->uName.length();
if(t>ul) ul=t;
t=it->gName.length();
if(t>gl) gl=t;
}
hl++;ul++;gl++;sl++;
if(!isd)
cout<<"total "<< bs/2<< endl;
for(vector<f_info>::iterator it=detailsV.begin();it!=detailsV.end();++it){
cout <<setw(pl)<< it->perm << setw(hl) << it->hLink << setw(ul) << it->uName 
<< setw(gl) << it->gName << setw(sl) << it->size << setw(dl) << it->time <<" "<< it->color << it->name 
<< none << it->linkColor << it->link <<none <<endl;
}
}
//for display only file names
else{
//stdout is terminal
if(isatty(1)){
/*int c;
struct winsize w;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
c = w.ws_col;
//bool f=true;*/
int s=detailsV.size();
for(int i=0;i<s;i++){
//f=!f;
cout<</*setw(detailsV[i].name.length())<<*/ detailsV[i].color <<detailsV[i].name << none;
cout<<endl;
/*if(f)
else
cout<<"  ";*/
}
//final next line
/*if(!f)
cout<<endl;*/


}else{// stdout is redirect to file
for(vector<f_info>::iterator it=detailsV.begin();it!=detailsV.end();++it){
cout<< it->name <<endl;
}
}
}
if(isR){
//cout<<path<<":"<<endl;
for(vector<f_info>::iterator it=detailsV.begin();it!=detailsV.end();++it){
if(it->perm[0]=='d'&&it->name!="."&&it->name!=".."){
cout<<it->fullName<<":"<<endl;
process(it->fullName.c_str(),opt);
cout<<endl;
}
//cout<<endl;
}
}



//for(unsigned int i=0;i<detailsV.size();i++){
  //  detail=detailsV.at(i);
   //getTime(timeString,detail.time);
  // cout<<detail.name<<" "<<detail.size<<" "<< detail.time /*timeString*/ << " "<<detail.perm<<" "<<detail.uName<<" "<<detail.gName<< endl;
   //timeString.clear();
//}

}
void init(vector<string>& files,string options){
int len=options.length();
char o;
for(int i=0;i<len;i++){
o=options.at(i);
if(o=='a'||o=='l'||o=='S'||o=='R'||o=='d'||o=='t')
continue;
cerr<<"invalid option --'"<< o<<"'"<<endl;
cerr<<"please see README file for more information."<<endl;
return;
}
 for(unsigned int i=0;i<files.size();i++){
   process(files.at(i).c_str(),options);
}
    
/* validateOptions(options);
 cout << "options: "<< endl;
 for( unsigned int i=0;i<options.size();i++)
  cout<< options.at(i)<< " ";
 cout << "files: "<< endl;
 for( unsigned int i=0;i<files.size();i++)
  cout<< files.at(i)<< " ";*/

}
int main(int argc,char* argv[]){
   /* struct dirent **namelist;
    struct stat *buf=NULL;
    char f_name[200];*/
    int c;
    vector<string> options;
    vector<string> files;
    
    c=0;
    
    if(argc != 1 ){
     c++;
     while(c<argc){
     if(argv[c][0]=='-')
     options.push_back(argv[c]+1);
     else 
     files.push_back(argv[c]);
     c++;
    }
 }
   if(files.size()==0) files.push_back(".");
   	string s("");   //init(files,options)
//	reverse(options.begin(),options.end());
for(vector<string>::iterator it=options.begin();it!=options.end();++it){
s+=*it;
}
   	init(files,s); 
  //f_name = malloc(200*(sizeof(char));
   /* int n;

    n = scandir(".", &namelist, 0, alphasort);
    
    if (n < 0)
        perror("scandir");
    else {
        while(n--) {
            memset(f_name,'\0',200);
            strcat(f_name,"./");
            if(namelist[n]->d_name[0]!='.'){
             strcat(f_name,namelist[n]->d_name);
             stat(f_name,buf);
             printf("%zd\n",(intmax_t)buf->st_size);
             
             
            printf("%s\t", namelist[n]->d_name);
            
}         //   free(namelist[n]);
        }
       // free(namelist);
    }*/
return 0;
}

