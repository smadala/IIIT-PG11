#include<iostream>
#include<stdlib.h>
int a[1000001];
using namespace::std;
void build(){
//a=(int *)calloc(1000001,sizeof(int));
a[0]=1;
a[1]=2;
for(int i=2;i<1000001;i++)
a[i]=(a[i-1]+a[i-2])%1000000007;
}
int main(){
int t,n;
build();
cin>>t;
while(t>0)
{
cin>>n;
cout<<a[n-1]<<endl;
t--;
}
return 0;
}
