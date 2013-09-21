#include<stdio.h>
int pd(int );
int main(){
int n;
while(1){
scanf("%d",&n);
if(n==-1)
return 0;
printf("%d\n",pd(n));
}
return 0;
}
int pd(int n){
int i,sum=0;
for(i=2;i*i<=n;i++){
if(n%i==0){
sum+=n/i;
sum+=i;
}
}
--i;
if(i*i==n)
sum-=i;
sum++;
return sum;
}
