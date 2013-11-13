#include<cstdio>
#include<iostream>
using namespace std;
int max(int a,int b){
	return a>=b?a:b;
}
int compute(int num){
	int sum,n2,n3,n4;
	n2=num/2;
	n3=num/3;
	n4=num/4;
	sum=n2+n3+n4;
	if(num >= sum){
		return num;
	}
	else{
		return	max(sum,compute(n2)+compute(n3)+compute(n4));
	}
}
int main(){
	int t,n;
	cin>>t;
	while(t-- > 0){
		cin>>n;
		cout<<compute(n)<<endl;
	}
	return 0;
}

