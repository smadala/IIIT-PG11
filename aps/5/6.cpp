#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int tc,n,a[1000],b[1000],j,i,count,max,temp;
	vector<int> t;
	scanf("%d",&tc);
	while(tc-- > 0){
		scanf("%d",&n);
		t.resize(n,0);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		max=0;
		for(i=0;i<n;i++){
			count=0;
			for(j=0;j<n;j++){
				if( (a[j] >= a[i] && b[j] >= b[i]) || (a[j] <= a[i] && b[j] <= b[i]))
				{
					t[i]++;
				//	count++;
				}
			}
			/*if(max < count){
				cout<<"i-"<<i<<"max "<<max<<"count "<<count<<endl;
				max=count;
			}*/
		}
		sort(t.begin(),t.end());
		temp=t[0];
		count=1;
		max=0;
	/*	for(i=0;i<n;i++){
			cout<<t[i]<<" ";
		}
		cout<<endl;*/

		for(i=1;i<n;){
			while( i < n && temp == t[i]){
				count++;
				i++;
			}
			//cout<<"count "<<count<<"val "<<temp<<endl;
			if( temp <= count ||  ( (temp - count) <= (n-i-1)))
			{
				max=temp;
			}
			if(i >= n)
				break;
			temp=t[i];
		//	cout<<"temp -"<<temp<<"i "<<i<<endl;
			count=0;
		}
		printf("%d\n",max);
		t.clear();
	}
	return 0;
}


