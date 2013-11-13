#include<iostream>
using namespace std;
int *a,n;
int *post;
int cur;
void con(int s,int e){
	int t=s;
post[cur--]=a[s];
if (s >= e) return ;
while(a[s] >= a[++t] && t != e);
if(e == t && a[s] > a[e]){
	con(s+1,e);
	return;
}
con(t,e);
if( s+1 <= t-1)
con(s+1,t-1);
}
int main(){
	int q,temp;
	cin>>n;
	a=new int[n];
	post=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cur=n-1;
	con(0,n-1);
/*	for(int i=0;i<n;i++){
	cout<<post[i]<<" ";
	}*/
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>temp;
		cout<<post[temp-1]<<endl;
	}
	return 0;
}

