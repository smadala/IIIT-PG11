#include<iostream>
#include<map>
using namespace std;
/*void find(int *a, map<int,int> &bmap,int n){
	int res[n],k,temp,bi;
	for(int i=1;i<n;i++){
		k=a[i];
		bi=bmap[k];
		temp=bi-i;
		if ( temp < 0)
			temp+=n-1;
		res[i]=temp;
	}

	int i,len=1,val,max=1,max_val=res[1];
		val=res[1];
	for(i =2;i<n;i++){

		if( val == res[i] ){
			len++;
			continue;
		}
		else{
			if( len > max ){
				max=len;
				max_val=res[i-1];
			}
			len=1;
			val=res[i];
		}
	}
	if( len > max){
		max=len;
		max_val=res[i-1];
	}
	if ( len == n-1){
		cout<<max_val<<endl;
	}
	else{
		cout<<(n-1-max)<<endl;
	}
}*/
void find(int *a,int *b,int n){
	int count=0;
	for(int i=n-1,j=n-1;i>=0;i--){
		if (a[i] == b[j] ){
			count++;
			j--;
		}
	}
	cout << n-count <<endl;

}
int main(){
	int t,n;
	int *a,*b;
	cin>>t;

	while(t>0){
		cin>>n;
		a=new int[n];
		b=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		find(a,b,n);
		delete [] a;
		delete [] b;
		t--;
	}
	return 0;
}


