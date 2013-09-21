#include<stdio.h>
#include<limits.h>
long int comb(int,int);
int a[1001][1001];
void buildTri(){
int i,j;
a[0][0]=1;
for(i=1;i<=1000;i++){
a[i][0]=1;
for(j=1;j<=1000;j++){
if(i==j)
{
a[i][j]=1;
break;
}
a[i][j]=(a[i-1][j]+a[i-1][j-1])%1000000007;
}
}
}
int main(){
int n,r;

buildTri();
while(1){
scanf("%d",&n);
if(n==-1)
return 0;
scanf("%d",&r);
//f=comb(n,r);
printf("%d\n",a[n][r]);
}
return 0;
}

long int comb(int n,int r){
int i,j,a[500],b[500];
unsigned long int sum=1;
if(n-r<r)
r=n-r;
for(i=0,j=r;i<r;i++,j--){
b[i]=j;
}
for(i=0,j=n;i<r;i++,j--){
a[i]=j;
}
for(i=0;i<r;i++){
for(j=0;j<r;j++){
if(b[i]!=1&&a[j]!=1&&a[j]%b[i]==0){
a[j]=a[j]/b[i];
b[i]=1;
break;
}else if(b[i]!=1&&a[j]!=1&&b[i]%a[j]==0){
b[i]=b[i]/a[j];
a[j]=1;
}
}
}
for(i=0;i<r;i++){
if(a[i]!=1)
sum=sum*a[i];
/*if(sum>INT_MAX){
sum=sum%1000000007;
}*/
}
return sum%1000000007;
}

