#include<stdio.h>
#include<limits.h>
long int comb(int,int);

int main(){
int n,r;
long int f=0;
while(1){
scanf("%d",&n);
if(n==-1)
return 0;
scanf("%d",&r);
f=comb(n,r);
printf("%ld\n",f);
}
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

