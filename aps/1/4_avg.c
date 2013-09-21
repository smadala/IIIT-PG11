#include<stdio.h>
int  sumAll(int,int,int,int);

long long int mul1(int min,int max,int n);
int gcd(int m,int n){
if(m==n)
return m;
else if(m>n)
return gcd(m-n,n);
else 
return gcd(m,n-m);
}
int lcm(int n,int m){
return n*m/gcd(n,m);
}
int main(){
int t,l,u,a,b;
scanf("%d",&t);
while(t>0){
scanf("%d",&l);
scanf("%d",&u);
scanf("%d",&a);
scanf("%d",&b);
printf("%d\n",sumAll(l,u,a,b));
t--;
}
return 0;
}
void min1(int l,int u,int a,int *b){
int i;
for(i=l==0?1:l;;i++){ //check boundary cond
if(i%a == 0)
break;
}
b[0]=i;
for(i=u;;i--)
{
if(i%a==0)
break;
}
b[1]=i;
}
int sumAll(int l,int u,int a,int b){
int fb[2],c;
long long int sumA,sumB,temp;

min1(l,u,a,fb);
sumA=mul1(fb[0],fb[1],a);
min1(l,u,b,fb);
sumB=mul1(fb[0],fb[1],b);
c=lcm(a,b);
min1(l,u,c,fb);
temp=mul1(fb[0],fb[1],c);
/*if(temp>sum){
z=temp;
temp=sum;
sum=z;
}*/
sumA=(sumA+sumB-temp)%1000000007;

//num div * avg
/*sum=((max-min)/a+1)*((min+max)/2);
sum=sum%1000000007;

for(i=l;i<=u;i++)
{
if(i%b==0)
break;
}
for(;i<=u;i=i+b){
if(i%a!=0)
sum=(sum+i)%1000000007;
}*/
return sumA;
}
long long int mul1(int min,int max,int n){
long long int m,a;
long long int sum=0;
if(min>max)
return 0;
m=(max-min)/n+1;
a=((min+max))/2;
sum=a*m;

if((min+max)%2!=0){
sum=sum+m/2;
}
//a++;
/*for(i=0;i<m;i++){
sum=(sum+a)%1000000007;
}*/
return sum;
}

