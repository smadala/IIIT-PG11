#include<iostream>
#include<string>
using namespace std;
int id[10];
int s[10];
void init(){
	for(int i=0;i<10;i++){
		id[i]=i;
		s[i]=1;
	}
}
int root(int i){
	while(i != id[i]) i =id[i];
	return i;
}
int con(int p, int q){
	if (root(p) == root(q))
		return 1;
	return 0;
}
int uni(int p,int q){
	int i=root(p);
	int j=root(q);
	if(s[i] < s[j] ){ 
		id[i]=j;
		s[j]+=s[i];
	}else{
		id[j]=i;
		s[i]+=s[j];
	}
}

int main(){
	int pairs,p,q;
	init();
	cin>>pairs;
	while(pairs > 0){
		cin>>p;
		cin>>q;
		if( con(p,q) == 0)
		{
			cout<<"connected"<<endl;
			uni(p,q);
		}
		pairs--;
	}
	string s[10];
	int ch;
	for( int i=0;i<10;i++){
		ch=root(i);
		s[ch]=i;
	}
	for(int i=0;i<10;i++){
		cout<<s[i]<<endl;
	}
}




