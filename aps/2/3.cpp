#include<iostream>
#include<stdlib.h>
using namespace::std;

long long int** matMul(long long int **a,long long int **b, int a_r,int a_c,int b_c){
/*for(int i=0;i<a_r;i++)
   for(int j=0;j<b_c;j++)
     r[i][j]=0;*/
long long int **r;
r=(long long int **)calloc(a_r,sizeof(long long int *));
for(int i=0;i<a_r;i++)
   r[i]=(long long int *)calloc(b_c,sizeof(long long int *));
      
for(int i=0;i<a_r;i++)
  for(int j=0;j<b_c;j++)
   for(int k=0;k<a_c;k++)
       r[i][j]=(r[i][j]+(a[i][k]*b[k][j])%1000000007)%1000000007;
return r;
}

long long int** power(long long int **a,/* long long int **t1, long long int **t2,*/int n,int s){
long long int **t1=NULL,**t2=NULL;
   if(n==1){
  return a;
/* for(int i=0;i<s;i++)
  for(int j=0;j<s;j++)
   r[i][j]=a[i][j];
    return;*/
}
if(n==0)
{
long long int **r;
r=(long long int **)calloc(s,sizeof(long long int *));
for(int i=0;i<s;i++)
   r[i]=(long long int *)calloc(s,sizeof(long long int *));
for(int i=0;i<s;i++)
  for(int j=0;j<s;j++)
   r[i][j]=1;
return r;
}
   t1= power(a,/*t1,t2*/n/2,s);
   t2= matMul(t1,t1,s,s,s);
   if(n%2==0){
   return t2;
}
   else
   return  matMul(t2,a,s,s,s);
} 
void cal(int n){
long long int **a, **r/*,**t1,**t2*/;
int row=3,col=3;
int sum=0;
if(n==1){
cout<<1<<endl;
return;
}
else if(n==2){
cout<<2<<endl;
return;
}
 
a=(long long int **)calloc(row,sizeof(long long int*));
for(int i=0;i<row;i++)
 a[i]=(long long int *)calloc(col,sizeof(long long int *));

a[0][0]=0;a[0][1]=1;a[1][0]=1;a[1][1]=1;

/*r=(long long int **)calloc(row,sizeof(long long int *));
for(int i=0;i<row;i++)
   r[i]=(long long int *)calloc(col,sizeof(long long int *));

t1=(long long int **)calloc(row,sizeof(long long int *));
for(int i=0;i<row;i++)
   t1[i]=(long long int *)calloc(col,sizeof(long long int *));

t2=(long long int **)calloc(row,sizeof(long long int *));
for(int i=0;i<row;i++)
   t2[i]=(long long int *)calloc(col,sizeof(long long int *));*/

r=power(a,/*t1,t2*/n-1,row);
for(int i=0;i<col;i++)
sum=( sum + r[1][i])%1000000007;
cout<<sum<<endl;
}
int main(){
int t,n;
cin>>t;
while(t>0){
cin>>n;
cal(n);
t--;
}
return 0;
}
