#include<stdio.h>
int partition(int *a, int l, int hi)
{
int t,i = l, j = hi+1;
while (1)
{
while (a[++i] < a[l])
    if (i == hi) break;
while (a[l] < a[--j])
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
int i,a[8]={2, 4, 6, 8 ,10, 8, 6, 2};
sort(a,0,7);
for(i=0;i<10;i++){
printf("%d ",a[i]);
}
return 0;
}


