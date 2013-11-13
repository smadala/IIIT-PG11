#include<stdio.h>
#include<iostream>
using namespace std;
int a[10000];
int main(){
	int t,n,i,tn=0;
	long long pp,p,c;
	scanf("%d",&t);
	while( t-- > 0){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		pp=0;
		p=0;

		for(i=0;i<n;i++){
			if(pp + a[i] > p){
				c=p;
				p=pp+a[i];
				pp=c;
			}
			else{
				pp=p;
			}
		}
		tn++;
		printf("Case %d: %lld\n",tn,p);
	}
}
				





