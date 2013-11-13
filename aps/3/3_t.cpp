#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	string s="00099";
	string r=s;
	reverse(r.begin(),r.begin()+4);
	cout<<s.replace(3,2,s.substr(0,2))<<endl;
	cout<<r<<endl;
	return 0;
}

