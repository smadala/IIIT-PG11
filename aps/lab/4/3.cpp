#include<iostream>
#include<stdlib.h>
using namespace::std;
void process(int *a,int n, int max){
	int temp=0;
	int lo=0;
	int frq=0;
	int *f;
	f=(int *)malloc(n*sizeof(int));
	int *s=(int *)malloc(n*sizeof(int));
      for(int i=0;i<n;i++){
		     temp+=a[i];
                     f[i]=++frq;
		     s[i]=temp;
		     if(temp > max){
			     while(temp > max){
				     temp-=a[lo++];
				     f[i]--;
			     }
			     s[i]=temp;
			     frq=f[i];
		     }
      }
      int gre=f[0],j=0;
      for(int i=1;i<n;i++){
	      if(f[i] == gre){
		      if(s[i] > s[j]){
			     j=i; 
			     gre=f[i];
		      }
	      }else if(f[i] > gre){
		      j=i;
		      gre=f[i];
	      }
      }
      cout<<s[j]<<" "<<f[j]<<endl;
}
int main(){
	int t,n,max,*a;
	cin>>t;
	while(t > 0){
		cin>>n;
		cin>>max;
		a=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		process(a,n,max);
		t--;
	}
	return 0;
}
