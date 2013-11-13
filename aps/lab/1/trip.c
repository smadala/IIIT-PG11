#include<stdio.h>
#include<stdlib.h>
int logic(int a[],int size){
int sum=0,i,avg,mov=0;

for(i=0;i<size;i++){
sum=sum+a[i];
}

if(sum % size !=0)
return -1;
avg =sum/size;
for(i=0;i<size;i++){
if(a[i]>avg){
mov=mov+a[i]-avg;
}
}
return mov;

}
int main(){
int numSet,i;
int *a;
while(1){
numSet=0;
scanf("%d\n",&numSet);
if(numSet == -1)
return 0;
a=(int*)malloc(numSet*sizeof(int));
for(i=0;i<numSet;i++)
scanf("%d",&a[i]);
printf("%d\n",logic(a,numSet));
}
return 0;
}
