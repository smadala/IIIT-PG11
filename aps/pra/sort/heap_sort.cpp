#include<iostream>
using namespace std;
void swim(int *a,int pos){
	int temp;
	while ( pos > 1 && a[pos] < a[pos/2] ){
		temp=a[pos];
		a[pos]=a[pos/2];
		a[pos/2]=temp;
		pos=pos/2;
	}
}
void sink(int *a,int pos,int n){
	int child=2*pos,aux;
	while( n >= child ){

		if( child < n && a[child] < a[child+1] ) child++;

		if( a[pos] < a[child] ) {
			aux=a[pos];
			a[pos]=a[child];
			a[child]=aux;
			pos=child;
			child=child*2;
			continue;
		}
		break;
	}
	return;
}
void delMax(int *a,int n){
	int temp=a[1];
	a[1]=a[n];
	a[n]=temp;
	sink(a,1,n-1);
}

void heap_sort(int *a,int n){

	for(int i=n/2;i >= 1;i--){
		sink(a,i,n);
	}
	int size=n;
	while( size > 1){
		delMax(a,size--);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return;
}


int main(){
	int *a,n;
        cin>>n;
        a=new int[n+1];
        for(int i=1;i<=n;i++)
                cin>>a[i];
        heap_sort(a,n);
        delete []a;
	return 0;
}
