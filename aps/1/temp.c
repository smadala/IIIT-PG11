#include<stdio.h>
#include<string.h>
int sumAl(int);
int main(){
int n;
while(1){
scanf("%d",&n);
if(n==-1)
return 0;
printf("%d\n",sumAl(n));
}
return 0;
}
int sumAl(int n){
int a[6000],c,j,t,d,i,r;
int sum=0;
for(i=0;i<6000;i++)
a[i]=-1;
t=n;
a[0]=2;
t--;
d=1;
for(i=2;i<=n;i++){
c=0;
for(j=0;j<d;j++){
r=a[j]*2+c;
a[j]=r%10;
c=r/10;
if(c!=0){
if(a[j+1]==-1){
d++;
a[j+1]=c;
break;
}
}
}
}
for(i=0;i<d;i++)
sum+=a[i];
return sum;
}
