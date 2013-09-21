#include<stdio.h>
int feb(int );
int main(){
int t,i,j,n,sum,pre,temp;
scanf("%d",&t);
for(i=0;i<t;i++){
scanf("%d",&n);
sum=1;
pre=0;
temp=0;
for(j=1;j<=n;j++){
temp=sum;
sum=(sum+pre)%(1000000007);
pre=temp;
}
printf("%d\n",sum);
}
return 0;
}


