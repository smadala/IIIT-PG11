#include<iostream>
#include<stdlib.h>
using namespace::std;
void cal(long long int n){
	char *res;
	long long int i=-1,r;
	res=(char*)calloc(100,sizeof(char));
	

while(n>0){
    r= n%5;
    n=n/5;
    switch(r){
	    case 0: res[++i]='r';n--;break;
	    case 1: res[++i]='k';break;
	    case 2: res[++i]='u';break;
	    case 3: res[++i]='m';break;
	    case 4: res[++i]='a';break;
    }
}
for(int j=i;j>=0;j--)
cout<<res[j];
cout<<endl;
}
int main(){
	int t;
	long long int n;
	cin>>t;
	while(t>0)
	{
		cin>>n;
		cal(n);
		t--;
	}
}
