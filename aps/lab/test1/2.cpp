#include<iostream>
int a[1000001];
using namespace std;
void build(){
	int count=0,i;
	a[2]=1;
	count=1;
	for(i=3;i<1000001;i++){
		if(i%2 != 0)
			count++;
		a[i]=count;
	}
}
int main(){

	int t,n;
	build();
	cin>>t;
	while(t >0){
		cin>>n;
		cout<<a[n]<<endl;
		t--;
	}
}
