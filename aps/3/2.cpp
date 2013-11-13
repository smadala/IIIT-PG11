#include<iostream>
#include<string>
using namespace std;
int sum[15];
int each[15];
int times[10]={0,0,0,1,1,1,1,2,2,3};
int rec[10]={0,0,0,1,0,0,0,1,0,1};
void build(){
	each[0]=1;
	for(int i=1;i<=14;i++){
		each[i]=each[i-1]*3;
		sum[i]=sum[i-1]+each[i];
	}
}
int find(string s){
	int len,i,f,temp;
		len = s.length();

		i=0;
		if( i < len ){
			f=((int)s.at(i))%48;
			if ( times[f] == 0  )
				return 0;
			
			if ( rec[f] == 0)
				return times[f] *  each [len -1];
			if( len ==1 ){
				return times[f];
			}
			if (f == 3 )
				return find(s.substr(1,len-1));
			else if ( f == 7)
				return each[len-1] + find(s.substr(1,len-1));
			else{ 
				temp=find(s.substr(1,len-1));
			//	cout<<temp << " temp 2*each[len-1] " << 2* each[len-1] <<endl;
				return 2 * each[len-1] + temp; 
				}
	/*		temp=find(s.substr(1,len-1));
			temp+=each[len-1];
			cout<<res<<"res temp"<<temp<<endl;
			return res + temp;*/
		}
//		cout<<"end"<<endl;
		return 1;
}

int main(){
	string s;
	int res=0;
	build();

       cin>>s;
	while(s != "0"){
/*		len = s.length();
		res = sum[s.length()-1];
		i=0;
		while( i < len ){
			f=((int)s.at(i))%48;
			if ( times[f] == 0 )
				break;
		
			res+= times[f] * each [len-i-1];
			i++;
		}*/
		res=sum[s.length()-1];
		//cout<<s<<endl;
		res += find(s);
		cout<<res<<endl;
		cin>>s;
	}
	return 0;
}

