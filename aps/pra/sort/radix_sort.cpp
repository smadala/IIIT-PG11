#include<iostream>
using namespace std;
void radix_sort(int *a,int n){
	int b[n],max=a[0],exp=1;
	for(int i=1;i<n;i++){
		if(a[i] > max)
			max=a[i];
	}
	while( max/exp > 0 ){
		int buk[11]={0};
		//# of times each digit occur
		for( int i=0;i<n;i++){
			buk[(a[i]/exp)%10 + 1 ]++;
		}
		// starting index of each digit
		for(int i=1;i<10;i++){
			buk[i]+=buk[i-1];
			cout<<buk[i]<<" "<<i<<endl;
		}
		// copy each number to aprop positions
		for(int i=0;i<n;i++){
			b[buk[(a[i]/exp)%10]++]=a[i];
		}
		//copy to original array
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
			a[i]=b[i];
		}
		cout<<endl;
		exp*=10;
	}
}



int main(){
	int *a,n;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	radix_sort(a,n);
	delete []a;
	return 0;
}

