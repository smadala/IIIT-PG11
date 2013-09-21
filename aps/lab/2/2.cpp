#include<stdio.h>
#define SZ 10000
#define ABS(X,Y) X-Y>0?X-Y:Y-X
int partition(int *a, int l, int hi)
{
int t,i = l, j = hi+1;
while (1)
{
while (a[++i] > a[l])
    if (i == hi) break;
while (a[l] > a[--j])
     if (j == l) break;
if (i >= j) break;
t=a[i];
a[i]=a[j];
a[j]=t;
}
t=a[l];
a[l]=a[j];
a[j]=t;
return j;
}
void sort(int *a, int l, int hi)
{
if (hi <= l) return;
int j = partition(a, l, hi);
sort(a, l, j-1);
sort(a, j+1, hi);
}
int main(){
int i,j,in,pn,a[SZ],b[SZ],s,t;
scanf("%d",&t);
while(t>0){
scanf("%d",&in);
for(i=0;i<in;i++)
scanf("%d",&a[i]);
scanf("%d",&pn);
for(i=0;i<pn;i++)
scanf("%d",&b[i]);
sort(a,0,in-1);
sort(b,0,pn-1);
for(i=0;i<in;i++)
printf("%d ",a[i]);
printf("\n");
for(i=0;i<pn;i++)
printf("%d ",b[i]);
printf("\n");

s=ABS(a[0],b[0]);
i=0;j=0;
while(i<in && j<pn){
if(a[i]>b[j]){  a[i]-b[j]<s?(s=a[i]-b[j]):0;  j++;}
else if(a[i]<b[j]){ b[j]-a[i]<s?(s=b[j]-a[i]):0; i++;  }
else {s=0;break;}
}
printf("%d\n",s);
t--;
}
return 0;
}
