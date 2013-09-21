#include<stdio.h>
#define REM 1000000007
void cal(long long int n){
long long int sum=0;
long long int i=1;
while(i*i<=n){
sum=(sum+(i*i))%REM;
i++;
}
i=i-1;
//sum=((i*(i+1)%REM)*((2*i+1)%REM))/6%REM;
printf("%lld %lld\n",i,sum);
//i=i%1000000007;
/*sum=(i*(i+1))%REM;
sum=(sum* (2*i+1))%REM;
sum=sum/6;
a[1]=sum%REM;*/
//a[1]=sum;

}
int main(){
long long int n;
//long long int a[2];
//printf("%d\n",sizeof(int));
while(1){
scanf("%lld",&n);
if(n==0)
return 0;
cal(n);
//printf("%lld %lld\n",cal(n));
}
return 0;
}
