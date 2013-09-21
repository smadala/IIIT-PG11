#include<stdio.h>
#include<string.h>
#define SZ 10000001
long int a[SZ];
long int np;
int main(){
long long int i,j;
long int l,u;
long int d;

for(i=2;i<SZ;i=i+2)
a[i]=1;
a[2]=++np;
for(i=3;i<SZ;){
a[i]=++np;
for(j=i*i;j<SZ;j=j+i)
a[j]=1;
for(i=i+1;i<SZ&&a[i]!=0;i++){
a[i]=np;
}
}
for(i=0;i<100;i++){
printf("%lld %ld\n",i,a[i]);
}
while(1){
scanf("%ld %ld",&l,&u);
if(l==0&&u==0)
return 0;
d=a[u]-a[l];
if(a[l]!=a[l-1])
d++;


printf("%ld\n",d);
}
return 0;
}

