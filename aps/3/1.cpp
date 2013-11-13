#include<iostream>
using namespace std;

int merge(int *a,int *b,int l, int m, int h){
	int i=l,j=m+1,c=0;
	for(int k=i;k<=h;k++){
	b[k]=a[k];
	//cout << b[k];
}
	////cout<<endl;
	for(int k=i;k <= h; k++){
		if(i > m) 
			a[k]=b[j++];
		else if ( j > h ) 
			a[k]=b[i++];
		else if ( b[j] < b[i] ){

			a[k]=b[j++];
			c+=(m-i+1);
			//cout<<c<<m<<i<<"cmi"<<endl;
		}
		else 
			a[k]=b[i++];
	}
	//cout<<" low "<< l << h<< c<< endl;
	return c;
}

int find(int *a, int *b, int l, int h ){
	int m = l + ( h - l) / 2,c=0;

	if ( l >= h)
		return 0;
	c=find(a,b,l,m);
	c+=find(a,b,m+1,h);
	return c+merge(a,b,l,m,h);

}
int main(){
	int t,n,*a,*b;
	cin>>t;
	while ( t > 0){
		cin>>n;
		a=new int[n];
		b=new int[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<find(a,b,0,n-1)<<endl;
		/*for(int i=0;i<n;i++){
			cout<<a[i];
		}*/
		
		//cout<<endl;
		delete[] a;
		delete[] b;
		t--;
	}
	return 0;
}
	
