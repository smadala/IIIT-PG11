#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct line{
	int f;
	int s;
};
bool linesort(struct line *p1,struct line *p2){
	return p1->f < p2->f || (p1->f== p2->f && p1->s < p2->s);
}
int main(){
	struct line *bridges[1000];
	int lis[1000];
	int i,t,n,count,max,j;
	scanf("%d",&t);
	while( t-- > 0){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			bridges[i]=new line;
			scanf("%d", &bridges[i]->f);
		}
		for(i=0;i<n;i++){
			scanf("%d",&bridges[i]->s);
		}
		sort(bridges,bridges+n,linesort);
		max=0;
		for(i=0;i<n;i++){
	//		cout<<bridges[i]->f<<" " <<bridges[i]->s<<endl;

			count=0;
			for(j=0;j<i;j++){
				if( bridges[i]->s >= bridges[j]->s && lis[j] > count){
					count=lis[j];
				}
			}
			lis[i]=count+1;
			if( max < lis[i])
				max=lis[i];
		}
	//	cout<<endl;
		printf("%d\n",max);
	}
	return 0;
}
		


