#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<stack>
#include<stdlib.h>

using namespace std;
vector< vector<int> > g;
vector<bool> visitedNodes; 
int numNodes,numEdges;
stack<int> s;
/*class Graph{
	int numNodes;
	int numEdges;
	vector< list<int> > connections;
	public:	Graph(){
	}
	public:Graph(int nodes,int edges){
		numNodes=nodes;
		numEdges=edges;
		connections.resize(nodes);
	}
	public:	void connect(int u,int v){
		connections[u].push_back(v);
		connections[v].push_back(u);
	}
	public:	list<int> adj(int node){
		return connections[node];
	}
	public: int getNumNodes(){
			return numNodes;
		}
	public: void clear(){
			connections.clear();
		}
};*/

void dfs(int src){
	vector<int> adjs;
	int cur;

	s.push(src);
	visitedNodes[src]=true;
	while(!s.empty()){
		cur=s.top();
		s.pop();
		visitedNodes[cur]=true;
		adjs= g[cur];
		for(vector<int>::iterator it=adjs.begin(); it!= adjs.end();it++){
			if(!visitedNodes[*it])
				s.push(*it);
		}
	}
}
int numberOfConnectedComp(){
	int numCom=0;
	vector<int> adjs;
	vector<int>::iterator it;
	int cur;
		for(int i=0;i<numNodes;i++){
			
			if(!visitedNodes[i]){
				//cout<<numCom++<<endl;
				numCom++;
				if(g[i].size()!=0){
					s.push(i);
					visitedNodes[i]=true;
					while(!s.empty()){
						cur=s.top();
						s.pop();
						visitedNodes[cur]=true;
						adjs= g[cur];
						for(it=adjs.begin(); it!= adjs.end();it++){
							if(!visitedNodes[*it])
								s.push(*it);
						}
					}
					//dfs(i);
				}
			}
		}
		return numCom;
}

int main(){
	int t;
	int u,v;
	cin>>t;
	/*g.resize(100000);
	visitedNodes.resize(100000);*/
	
	while(t-- > 0){
//		cin>>numNodes>>numEdges;
		scanf("%d %d",&numNodes,&numEdges);
		g.resize(numNodes);
		visitedNodes.resize(numNodes);
		for(int i=0;i<numEdges;i++){
			//cin>>u>>v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		//cout<<numberOfConnectedComp()<<endl;
		printf("%d\n",numberOfConnectedComp());
		g.clear();
		visitedNodes.clear();
	}
	g.clear();
	visitedNodes.clear();
	return 0;
}
