#include<stdio.h>
void cal(long long int n,int *a){
long long int sum=0;
int i=1;
long long int s=1;
for(i=1;s<=n;i++)
{
sum=(sum+(s))%1000000007;
s=(i+1)*(i+1);
}
sum=(sum)%1000000007;
a[0]=--i;
a[1]=sum;
}
int main(){
long long int n;
int a[2];
while(1){
scanf("%lld",&n);
if(n==0)
return 0;
cal(n,a);
printf("%d %d\n",a[0],a[1]);
}
return 0;
}
