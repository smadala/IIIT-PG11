#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace::std;
void process(int *a,int n){
	int i;
	int *r=(int *)malloc(n*sizeof(int));
	stack<int> s;
	s.push(0);
     for(i=1;i<n;i++){
	     while(s.size() > 0  && a[i] > a[ s.top() ] ) {
		     r[s.top()] = a[i];
		     s.pop();
	     }
	     s.push(i);
     }
     while(s.size() > 0){
	     r[s.top()] =-1;
	     s.pop();
     }
for(int i=0;i<n;i++){
	cout<<r[i]<<" ";
}
cout<<endl;
}
int main(){
	int n;
	int *a;
	cin>>n;
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	process(a,n);
	return 0;
}

