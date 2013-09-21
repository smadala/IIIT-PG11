#include<stdio.h>
#define SZ 10000
int temp[SZ];
void merge(int  *a,int l,int m,int h){
int i,j,k;
for(i=l;i<=h;i++)
temp[i]=a[i];
j=l;
k=m+1;
for(i=l;i<=h;i++){
if(j>m) a[i]=temp[k++]; 
else if(k>h) a[i]=temp[j++];
else if(a[k]<a[j]) a[i]= temp[k++];
else a[i]=temp[j++];
}
}
void sort(int *a,int n){
int i,j;
for(i=1;i<n;i=i+i)
  for(j=0;j<n-i;j+=i+i){
    merge(a,j,j+i-1,(j+i+i-1>n-1?n-1:j+i+i-1));
}
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
sort(a,in);
sort(b,pn);
for(i=0;i<in;i++)
printf("%d ",a[i]);
printf("\n");
for(i=0;i<pn;i++)
printf("%d ",b[i]);
printf("\n");

s=a[0]-b[0]>0?a[0]-b[0]:b[0]-a[0];
for(i=0;i<in;i++){
for(j=0;j<pn;j++){
if(a[i] > b[j]&&s > a[i]-b[j]) s=a[i]-b[j];
else if(b[j] > a[i] && s > b[j]-a[i])  s=b[j]-a[i];
else{s=0;break;}
}
if(s==0)
break;
}
printf("%d\n",s);
t--;
}
return 0;
}
