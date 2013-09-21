#include<iostream>
#include<string>
using namespace std;
int i;
char fi[100001];
void bin(int s){
	int re[100001];
	while(s > 0){
		if(s % 2 == 0)
			re[i]=0;
		else
			re[i]=1;
		s=s/2;
//		cout<<re[i];
		i++;
	}
//	couti<<endl;
	//char fi[20];
		fi[i]='\0';
	for(int j=i-1,k=0;j>=0;j--,k++){
		if(re[j] == 1)
		fi[k]='1';
		else{
		fi[k]='0';
		}
		//cout<<re[j]<<" "<<fi[k]<<endl;
	}
	//i;
	//cout<<"bin "<<i<<endl;
//	cout<<fi<<endl; 
}
int find(string s){
	int f=1;
	//cout<<"fin "<<i<<endl;
	//cout<<"fin "<<fi<<endl;
int l=s.length();	
	if( i > l)
		return 0;
	for(int j=i-1,k=s.length()-1;j>=0;j--,k--){
		//cout<<j << " "<<k<<endl;
		if( s.at(k) == '1' && fi[j] == '0' ){
			f=0;
			break;
		}
	}

return f;
}
int main(){
int t,s;
int c=1;
cin>>t>>s;
string num;
bin(s);

	//cout<<"main "<<i<<endl;
int f;
while(t>0){
	cin>>num;
	f= find(num);
	if(f == 0)
		cout<< "Case "<<c<<": No"<<endl;
	else
		cout<< "Case "<<c<<": Yes"<<endl;
	t--;
	c++;
}
//cout<<b<<endl;
return 0;
}
