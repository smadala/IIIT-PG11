#include<iostream>
#include<stdlib.h>
using namespace::std;
int in,r,c;
void find(bool **a,int ci, int cj, int *fi,int *fj){
	bool got=false;
        *fi=-1,*fj=-1;
	for(int i=ci;i>=0;i--){
		for(int j=c-1;j>=0;j--)
                     if(a[i][j]==false){
			     got=true;
			     *fi=i;
			     *fj=j;
                             break;
		     }
           if(got) break;
         }
}
void flip(bool **a,int fi, int fj)
{
	for(int i=0;i<=fi;i++)
		for(int j=0;j<=fj;j++)
                     a[i][j]=!a[i][j];
}
int build(bool **a,int ci,int cj){
	int fi,fj;
	find(a,ci,cj,&fi,&fj);
	if(fi==-1&&fj==-1)
		return 0;
	else{
		flip(a,fi,fj);
		return 1+build(a,fi,fj);
	}
}
int main(){
	bool **a;
	cin>>r>>c;
	  a=(bool**)malloc((r)*sizeof(bool*));
	         for(int i=0;i<r;i++)
	 	       a[i]=(bool*)malloc((c)*sizeof(bool*));

		 	for(int i=0;i<r;i++)
				for(int j=0;j<c;j++){
                                         cin>>in;
					 if(in==1)
					 a[i][j]=true;
					 else
						 a[i][j]=false;
				}
			cout<<build(a,r-1,c-1)<<endl;
			return 0;
}
