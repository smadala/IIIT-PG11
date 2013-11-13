#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
vector<int> elements;
int main(){
	int t,n,count,temp;
	vector<int> sum;
	cin>>t;
	while(t-- > 0){
		cin>>n;
		elements.resize(n+1);
		sum.resize(n+1);
		for(int i=1;i<=n;i++){
			scanf("%d",&temp);
			elements[i]=temp;
		}
		//sum[1]=elements[1];
		for(int i=1;i<=n;i++){
			if(elements[i]==0)
				count++;
			sum[i]=sum[i-1]+elements[i];
		}
		cout<<count<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<sum[j]-sum[i]<<" ";
				if( sum[j]-sum[i] == 0)
					count++;
			}
			cout<<endl;
		}
		cout<<count<<endl;
		elements.clear();
		sum.clear();

	}
	return 0;
}

