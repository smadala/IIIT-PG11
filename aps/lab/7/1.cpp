#include<iostream>
using namespace std;
int main(){
	int *a,*b,n;
	cin>>n;
	a=new int[n];
	b=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];

	}
	b[0]=1;
	int i,j,g;
	for(i=1;i<n;i++){
		g=-1;
		for(j=i-1;j>=0;j--){
			
			if( a[j] < a[i] && b[j] > g){
				g=b[j];
			}
		}
		if( g == -1){
			b[i]=1;
		}else
			b[i]=g+1;
	}
	int max=b[0];
	for(int i=0;i<n;i++){
		cout<<a[i]<<" "<<b[i]<<endl;
		if(max < b[i])
			max=b[i];
	}
	cout<<max<<endl;
	return 0;
}

