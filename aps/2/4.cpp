#include<iostream>
#include<stdlib.h>
using namespace::std;
int m;
long long int** matMul(long long int **a,long long int **b){

long long int **r,t;
int i,j,k;
r=(long long int **)malloc(3*sizeof(long long int *));
for(i=0;i<3;i++)
   r[i]=(long long int *)malloc(3*sizeof(long long int));
      
/*for(int i=0;i<3;i++){
   for(int j=0;j<3;j++)
   cout<<a[i][j]<<" ";
 cout<<endl;
}
for(int i=0;i<3;i++){
   for(int j=0;j<3;j++)
   cout<<b[i][j]<<" ";
 cout<<endl;
}*/
/*i=0;
while(i<3){
    j=0;
     while(j<3){
      k=0;
      t=0;
       while(k<3){
          t=(t+(a[i][k]*b[k][j])%m)%m;
        ++k;
}
r[i][j]=t;
++j;
}
++i;
}*/

for(i=0;i<3;i++)
  for(j=0;j<3;j++){
    t=0;
   for(k=0;k<3;k++){
       t=(t+(a[i][k]*b[k][j])%m)%m;
}
r[i][j]=t;
}
/*for(int i=0;i<3;i++){
   for(int j=0;j<3;j++)
   cout<<r[i][j]<<" ";
 llcout<<endl;
}*/
return r;
}

long long int** power(long long int **a,int n){

long long int **r;
r=(long long int **)malloc(3*sizeof(long long int *));
for(int i=0;i<3;i++)
   r[i]=(long long int *)malloc(3*sizeof(long long int ));
for(int i=0;i<3;i++)
  for(int j=0;j<3;j++){
   if(i==j)
   r[i][j]=1;
   else r[i][j]=0;
}

while(n>0){
if(n%2==1)
r=matMul(r,a);
a=matMul(a,a);
n=n/2;
}
return r;
} 
void cal(int n,int m){
long long int **a, **r;
int row=3,col=3;
long long int sum=0;
if(n==0){
cout<<1%m<<endl;
return;
}
else if(n==1){
cout<<2%m<<endl;
return;
}
 
a=(long long int **)malloc(row*sizeof(long long int*));
for(int i=0;i<row;i++)
 a[i]=(long long int *)malloc(col*sizeof(long long int));

a[0][0]=2;a[0][1]=5;a[0][2]=1;
a[1][0]=1;a[1][1]=0;a[1][2]=0;
a[2][0]=0;a[2][1]=0;a[2][2]=1;


r=power(a,n-1);
sum=(sum+(r[0][0]*2)%m)%m;
sum=(sum+(r[0][1]*1)%m)%m;
sum=(sum+(r[0][2]*3)%m)%m;


cout<<sum<<endl;
}
int main(){
int n;
cin>>n>>m;
cal(n,m);
return 0;
}
