#include<iostream>
using namespace std;
void find(int *a){
int m1=-1,m2=-1;
for(int i=0;i<4;i++){
	if(a[i] > m2){
		if(a[i] > m1){
			m2=m1;
			m1=a[i];

		}
		else
			m2=a[i];
	}
}
cout<<m1+m2<<endl;
}
int main(){
int t,a[4];
cin>>t;
while(t>0){
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	find(a);
	t--;
}
return 0;
}
