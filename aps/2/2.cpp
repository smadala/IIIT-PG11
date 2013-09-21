#include<iostream>
#include<stdlib.h>
void rowS(int **a,int m){
int sm=0,m=0;
for(int i=0;i<m;i++){
m=0;
sm=a[i][0];
for(int j=1;j<m;j++){
if(m+a[i][j]>0)
  m=m+a[i][j];
else m=0;
if(sm<m)
 sm=m;
}
}
}
void max(int **a,int m){

}
int main(){
int m,**a;
cin>>m;
a=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
 a[i]=(int *)malloc(m*sizeof(int));
for(int i=0;i<m;i++)
  for(int j=0;j<m;j++)
    cin>>a[i][j];
maxrec(a,m);
return 0;
}

