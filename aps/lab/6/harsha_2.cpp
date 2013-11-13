
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void doIt(vector<string> x,int y);

int main(){
	int cases=0,n;
	string ip;
	vector<string> stringarray;
	cin >> cases;
	for(int i=0;i<cases;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> ip;
			stringarray.push_back(ip);
		}
		sort(stringarray.begin(),stringarray.end());
		doIt(stringarray,n);
		stringarray.clear();
	}	
}

void doIt(vector<string> x,int y){
	int op;
	for(int i=0;i<y-1;i++){
		op=x[i+1].find(x[i]);
		if(op==0){
			cout <<"NO"<<endl;
			return;
		}
	}
	cout <<"YES"<<endl;
}
