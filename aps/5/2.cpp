#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int maxdia;
struct edge{
	int other;
	int weight;
};
vector< vector<struct edge*> > graph;
vector<bool> visited;
int diameter(int node){
	int max1=0,max2=0,temp=0;
	vector<edge*> adj;
	adj=graph[node];
	visited[node]=true;
	for(vector<edge*>::iterator it=adj.begin();it!=adj.end();it++){
//		cout<<(*it)->other<<endl;
		if(visited[(*it)->other])
			continue;
		temp=diameter((*it)->other);
//		cout<<"temp-"<<temp<<endl;
		temp=temp+(*it)->weight;

		if(temp > max1)
		{
			max2=max1;
			max1=temp;
		}else if(temp > max2){
			max2=temp;
		}
	}
	if(maxdia < max1+max2){
		maxdia=max1+max2;
	}
//	cout<<"node -"<<node<<" max1- "<<max1<<" max2- "<<max2<<" maxdia- "<<maxdia<<endl;

	return max1;
}

	

int main(){
	int t,n,i,u,v,w;
	struct edge *temp;
	scanf("%d",&t);
	while( t-- > 0){
		scanf("%d",&n);
		graph.resize(n+1);
		visited.resize(n+1);
		maxdia=0;
		for(i=1;i<n;i++){
			scanf("%d",&u);
			scanf("%d",&v);
			scanf("%d",&w);
			temp=new edge;
			temp->other=v;
			temp->weight=w;
			graph[u].push_back(temp);
			temp=new edge;
			temp->other=u;
			temp->weight=w;
			graph[v].push_back(temp);
		}
		diameter(1);
		printf("%d\n",maxdia);
		graph.clear();
		visited.clear();
	}
	return 0;
}
			
			


