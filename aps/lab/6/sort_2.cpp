#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	int t,n;
	bool yes=true;
	vector<string> numbers;
	string temp;
	cin>>t;
	while(t>0){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			numbers.push_back(temp);
		}
		sort(numbers.begin(),numbers.end());
/*		for(int i=0;i<n;i++){
			cout<<numbers[i];
		}*/
		for(int i=1;i<n;i++){
			if (numbers[i].find(numbers[i-1],0) == 0){				
				yes=false;
				break;
			}
		}
		if(yes)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		numbers.clear();
		yes=true;
		t--;
	}
	return 0;
}
