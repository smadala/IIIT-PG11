#include<stack>
#include<stdio.h>
using namespace std;
void find(int *a,int n){
	stack<int> s1;
	stack<int> s2;
	int i;
	s1.push(0);
	int count=0,eq,temp;
	for(i=1;i < n;i++){
		if (  a[i]  > a[s1.top()] ){
			while( (!s1.empty()) && a[i] > a[s1.top()] ){
				count+=n-i-1;
				s1.pop();
			}
		}
			s1.push(i);
	}
	s2.push(0);
	
	for(i=1;i<n;i++){
			while( (!s2.empty()) && a[s2.top()] < a[i] ){
			eq=1;
			temp=a[s2.top()];
			s2.pop();
			while ( !s2.empty() && temp == a[s2.top()] ){
				eq++;
				temp =a[s2.top()];
				s2.pop();
			}
			if( s2.size() >= 2){
				count+= (eq * (s2.size() -1) );

			}

			}
			s2.push(i);
	}
			while( !s2.empty()  ){
			eq=1;
			temp=a[s2.top()];
			s2.pop();
			while ( (!s2.empty()) && temp == a[s2.top()] ){
				eq++;
				temp =a[s2.top()];
				s2.pop();
			}
			if( s2.size() >= 2){
				count+= (eq * (s2.size() -1) );
				continue;
			}
			break;
			}

//	cout<<count<<endl;
	printf("%d\n",count);
}
int main(){
	int t,a[500001],n;
	scanf("%d",&t);
	while(t>0){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		find(a,n);
		t--;
	}
	return 0;
}
