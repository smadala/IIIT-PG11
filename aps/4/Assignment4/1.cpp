#include<iostream>
using namespace std;
int main(){
	int *pre,*in,n,t,pos,l,r,li,ri,root;
	bool same;
	cin>>n;
	pre=new int[n+1];
	in=new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>pos;
		pre[pos]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}
	cin>>t;
	while( t-- > 0){
		cin>>l;
		cin>>r;
		
		if(l == r){
			cout<<l<<endl;
			continue;
		}

		for(int i=1;i<=n;i++){
			if( l == in[i])
				li=i;
		}
		for(int i=1;i<=n;i++){
			if( r == in[i])
				ri=i;
		}
		if( li > ri){
			int temp;
			temp=ri;
			ri=li;
			li=temp;
		}

		root=in[li];

		for(int i=li+1;i<=ri;i++){
			if(pre[root] > pre[in[i]])
				root=in[i];
		}
		cout<<root<<endl;
	}
	return 0;
}
