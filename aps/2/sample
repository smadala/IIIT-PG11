#include<iostream>
#include<stdlib.h>
using namespace::std;
void compute(int *a,int n){
int t=0,st=0;
st=a[0];
for(int i=1;i<n;i++){
if(st<a[i])
st=a[i];
}
if(st<=0){
cout<<st<<endl;
return;
}

for(int i=0;i<n;i++)
{ 
 if(t+a[i]>0)
  t+=a[i];
 else 
  t=0;
 if(st<t)
 st=t;
}
cout<< st << endl;
}

int main(){
int n,*a;
cin >> n;
a=new int[n];
for(int i=0;i<n;i++)
cin >> a[i];
compute(a,n);
return 0;
}
