#include<stdio.h>
#include<map>
using namespace std;
//int a[1000000];
int b[1000000];
map<int,int> m;

int cal(int n){
	int i,count=0,times;
	//b[0]=a[0];
	m[b[0]]=1;
	for(i=1;i<n;i++){
		b[i]=b[i-1]+b[i];
		if(m.count(b[i])==1)
			m[b[i]]=m[b[i]]+1;
		else
			m[b[i]]=1;
	}
/*	for(i=0;i<n;i++){
	}*/
	if( m.count(0) ==1 && m[0] > 0 ){
		times=m[0];
		count+=(times*(times+1))/2;
		m.erase(0);
	}

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		times=it->second;
		if(times > 1)
			count+=(times*(times-1))/2;
	}
	m.clear();
	return count;
}

int main(){
	int t,n,i;
	scanf("%d",&t);
	while( t-- > 0){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		printf("%d\n",cal(n));
	}
	return 0;
}



