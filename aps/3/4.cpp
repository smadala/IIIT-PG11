#include<iostream>
#include<string>
using namespace std;
long long int findPair(string s){
	long long int count=1;
	long long  int total=1,temp;
	int i=s.length()-1;
	if( s[i] == '0' )
		i=i-2;
	for(;i>0;i--){
		if(s[i] == '0'){
			i--;
			continue;
		}

		if(s[i-1] == '1'){
			temp=total;
			total=total+count;
			count=temp;
		}else if(s[i-1] =='2' &&  s[i] < '7'){
			temp=total;
			total=total+count;
			count=temp;
		}else{
			count=total;
		}

	}
	return total;
}
			


	
/*	for(unsigned i=0;i<s.length();i++){
		if ( s[i] == '1' && s[i+1] != '\0' )
			count++;
		else if( s[i] == '2' &&  s[i+1] != '\0' && s[i+1] < '7' )
			count++;
	}
	return count;
}*/
int main(){
	string s;
	long long int p;
	cin>>s;
	while(s != "0")
	{
		p=findPair(s);
		cout<<p<<endl;
		cin>>s;
	}
	return 0;

}

