#include<iostream>
#include<stdlib.h>
using namespace::std;
int partition(int *a, int l, int h)
{
int t,i = l, j = h+1;
while (1)
{
while (a[++i] >  a[l])
    if (i == h) break;
while (a[l] > a[--j])
     if (j == l) break;
if (i >= j) break;
t=a[i];
a[i]=a[j];
a[j]=t;
}
t=a[l];
a[l]=a[j];
a[j]=t;
return j;
}
void sort(int *a, int l, int h)
{
if (h <= l) return;
int j = partition(a, l, h);
sort(a, l, j-1);
sort(a, j+1, h);
}

/*void remove(int *a,int n,int rem){
if(rem==1){
for(i=n-1;i<=0;i++){
if(
}
}
}*/

void total(int *a, int n)
{
int sum=0,rem;
for(int i=0;i<n;i++){
sum+=a[i];
}
int i=n-1;
for(;i>=0;i--){
if(a[i]!=0) break;
}
int z=i;
if(i==-1){cout<<0<<endl;return;}
for(;i>=0;i--){
if(a[i]%3!=0){
rem=sum-a[i];
if(rem%3==0)
break;
}
}
if(i==0||i==-1){

for(i=z;i>=1;i--)
{
rem=sum-a[i]-a[i-1];
if(rem%3==0){
break;
}
}
if(i!=0){
for(int j=0;j<n;j++){
if(i!=j&&i-1!=j)
cout<<a[j];
}
cout<<endl;
}
else
cout<<0<<endl;
}
else{
for(int j=0;j<n;j++)
if(i!=j)
cout<<a[j];
cout<<endl;
}
} 


void compute(int *a, int n){
sort(a,0,n-1);
if(a[n-1]!=0){
cout << -1<<endl;
return;
}
total(a,n);
}
int main(){
int n,*a;
cin >> n;
a=(int *)calloc(n,sizeof(int));
for(int i=0;i<n; i++)
cin >> a[i];
compute(a,n);
}
