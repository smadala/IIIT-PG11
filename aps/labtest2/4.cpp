#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int e,n,u,v;
	vector<int> degree;
	scanf("%d",&n);
	degree.resize(n);
	scanf("%d",&e);
	for(int i=1;i<=e;i++){
		scanf("%d",&u);
		scanf("%d",&v);
		degree[u-1]++;
		degree[v-1]++;
	}
	sort(degree.begin(),degree.end());
	if( degree[n-1] == n-1 && degree[n-2] == 1){
		printf("star topology");
	}else if(degree [n-1] == 2 && degree[0] == 2){
		printf("ring topology");
	}else if( degree[n-1] == 2 && degree[0] == 1 && degree[1] == 1){
		printf("bus topology");
	}else{
		printf("unknown topology");
	}
	return 0;
}

