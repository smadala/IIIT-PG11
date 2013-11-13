#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string putzero(int size){
	string s;
	for(int i=0;i<size;i++){
		s+="0";
	}
	return s;
}

void pal(string &s){
	string rev=s,temp;
	char left;
	int len=s.length(),next;
	int mid=len/2;
	bool m=false;
	bool even = (len % 2 == 0);
		if (!even  &&  s.at(mid) == '9'){

			reverse(rev.begin(),rev.end());
			rev = rev.substr(mid+1,(len-mid));
			temp = s.substr(mid+1,(len-mid));
			m=true;
		        if(temp.compare(rev) >= 0){
			next=mid-1;
			s[mid]='0';
			while( next >= 0 ){
				if ( s.at(next) == '9' )
					s[next--]='0';
				else{
					s[next]=s.at(next)+1;
					s=s.replace(mid+1,mid,putzero(mid));
					pal(s);
					return;
				}
			}
			if ( next == -1){
				s="1"+s.replace(mid+1,mid,s.substr(0,mid));
			}
			if ( len != (int)s.length()){
			pal(s);
			return ;
			}
		/*	if ( next == -1){
				s="1"+s;
			}
			len=s.length();
			mid=len/2;
			even= ( len % 2 == 0);
			rev=s;*/
		}
		}

	if ( len % 2 == 0){
		reverse(rev.begin(),rev.end());
		rev = rev.substr(mid+1,(len-mid));
		temp = s.substr(mid+1,(len-mid));
	//	bool m=false;

		if( (s.at(mid-1) == s.at(mid) &&  temp.compare(rev) == 0) || (temp.compare(rev) > 0) ){
	//		m=true;
			if( s.at(mid-1) != '9' && ! (s.at(mid-1) >= s.at(mid)) ){ // just increament if not 9 and left not greater
				  s[mid-1] = s.at(mid-1)+1;
			}else if(s.at(mid-1) == '9' && ! (temp.compare(rev) <= 0 )) { // 
			next=mid-1;
			//s[next]='0';
			while( next >= 0 ){
				if ( s.at(next) == '9' )
					s[next--]='0';
				else{
					s[next]=s.at(next)+1;
					s=s.replace(mid,mid,putzero(mid));
					pal(s);
					return;
				}
			}
			if ( next == -1){
				s="1"+s.replace(mid,mid,s.substr(0,mid));
			}
			if ( len != (int) s.length()){
			pal(s);
			return ;
			}
			/*len=s.length();
			mid=len/2;
			even= ( len % 2 == 0);
			rev=s;*/
			}
		}

		left  = s.at(mid-1) < s.at(mid)? s.at(mid-1)+1 : s.at(mid-1);
		if(s.at(mid-1) == s.at(mid)) left=s.at(mid);
		if(temp.compare(rev) > 0) left=s.at(mid-1);
		cout<<s.substr(0,mid-1)<<left<<left<<rev<<endl;
		//cout<<s.substr(0,mid-1)<<left<<left<<rev.substr(mid+1,(len-mid))<<endl;
		return;
	}
	else{
		if(!m){
		reverse(rev.begin(),rev.end());
		rev = rev.substr(mid+1,(len-mid));
		temp = s.substr(mid+1,(len-mid));
		}
	 	left = temp.compare(rev) >= 0 ? s.at(mid)+1 : s.at(mid) ;
		cout<<s.substr(0,mid)<<left<<rev<<endl;
		return;
	}

}
		


int main(){
	int t;
	string in;
	cin>>t;
	while( t > 0 ){
		cin>>in;
		pal(in);
		t--;
	}
	return 0;
}
