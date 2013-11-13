#include<cstdio>
#include<iostream>
using namespace std;
long long int max(long long int m,long long int n){
	return m>=n?m:n;
}
int a[1000000];
long long int compute(long long int num){
	if( num <= 11)
		return num;
	if(num < 1000000){
		if( a[num] == 0){
		/*	if(num >= sum){
				a[num]=num;
				return num;
			}
			else{*/
				a[num]=	max(num,compute(num/2)+compute(num/3)+compute(num/4));
				return a[num];
		//	}
		}else{
			return a[num];
		}
	}else{
		/*if(num >= sum){
			a[num]=num;
			return num;
		}
		else{*/
			return max(num,compute(num/2)+compute(num/3)+compute(num/4));
		//	return a[num];
	//	}
	}
}
int main(){
	long long int t,n;
	cin>>t;
	while(t-- > 0){
		cin>>n;
		printf("%lld\n",compute(n));
	}
	return 0;
}

