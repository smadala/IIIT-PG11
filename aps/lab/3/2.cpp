#include<iostream>
#include<stdlib.h>
using namespace::std;
void cal( int **a,int x1,int y1,int x2,int y2){
	 int sum=0;
/*	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
                      sum+=a[i][j];*/
  for(int i=0;x1+i<=x2;i++){
       // sum+=a[x1+i][y2]-a[x1+i][y1-1];
     sum+=a[x1+i][y2];
     if(y1!=0)
     sum-=a[x1+i][y1-1];
}

	cout<<sum<<endl;
}
void build ( int **a,int r, int c)
{
   
   for(int i=0;i<r;i++)
     for(int j=0;j<c;j++){
        // a[i][j]=a[i][j]+a[i][j-1];
         if(j!=0)
          a[i][j]+=a[i][j-1];
}
}
int main(){
	 int **a,r,c,t,x1,x2,y1,y2;
	cin>>r>>c>>t;
       // a=new int[r+1][c+1];
       a=( int**)malloc((r)*sizeof( int*));
       for(int i=0;i<r;i++)
	       a[i]=( int*)malloc((c)*sizeof( int*));
/*	for(int j=0;j<=c;j++)
               a[0][j]=0;
	for(int i=0;i<=c;i++)
               a[i][0]=0;*/

       
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>a[i][j];
         build(a,r,c);
	while(t>0){
		cin>>x1>>y1>>x2>>y2;
		cal(a,x1-1,y1-1,x2-1,y2-1);
		t--;
	}
return 0;
}
