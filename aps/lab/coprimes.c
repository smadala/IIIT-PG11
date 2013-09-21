#include<stdio.h>
int gcd(int , int);
int main(){
int m,n,g;
while(1){
scanf("%d",&m);
scanf("%d",&n);
if(m==0 && n==0)
return 0;
g=gcd(m,n);
//printf("%d\n",g);
if(g==1)
printf("%s\n","Yes");
else
printf("%s\n","No");
}
return 0;
}
int gcd(int m,int n){
 if(m==n)
return m;
else if(m < n)
return gcd(m,n-m);
else 
return gcd(m-n,n);
}

