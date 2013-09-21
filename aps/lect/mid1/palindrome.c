#include<iostream>
#include<stdio.h>
#include<string.h>
#define SZ 100
//int a[256];
using namespace::std;
void ispal(char *s,int l){
int *a;
a=new int[256];
char *t=s;
while(*t){
a[*t]++;
t++;
}
bool odd=l%2==0?false:true;
bool overodd=false;
bool ispal=true;
for(int i=0;i<256;i++){
if(a[i]%2==0)
continue;
if (odd && !overodd ) overodd=true;
else{
ispal=false;
break;
}
}
ispal?cout<<"is pal":cout<<"is not pal";
cout<<endl;
}
int main(){
char s[SZ];
gets(s);
ispal(s,strlen(s));
return 0;
}
