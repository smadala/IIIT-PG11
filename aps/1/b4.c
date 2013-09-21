#include<stdio.h>
unsigned long int  sumAll(int,int,int,int);
int main(){
int t,l,u,a,b;
scanf("%d",&t);
while(t>0){
scanf("%d",&l);
scanf("%d",&u);
scanf("%d",&a);
scanf("%d",&b);
printf("%ld\n",sumAll(l,u,a,b));
t--;
}
return 0;
}
unsigned long int mul1(int min,int max,int n){
unsigned int i,a,m;
unsigned long int sum=0;
m=(max-min)/n+1;
a=(min+max)/2;
for(i=0;i<m;i++){
sum=(sum+a)%1000000007;
}
return sum;
}
unsigned long int sumAll(int l,int u,int a,int b){
int i,min,max;
unsigned long int sum;

for(i=l==0?1:l;;i++){ //check boundary cond
if(i%a == 0)
break;
}
min=i;
for(i=u;;i--)//check boundary cond
{
if(i%a==0)
break;
}
max=i;
//num div * avg
sum=mul1(min,max,a);
sum=sum%1000000007;

for(i=l;i<=u;i++)
{
if(i%b==0)
break;
}
for(;i<=u;i=i+b){
if(i%a!=0)
sum=(sum+i)%1000000007;
}
return sum;
}
/*unsigned long int mul(int min,int max,int n){
}*/
