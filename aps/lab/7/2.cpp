#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;
/*class graph{
	int numNodes;
	int numEdges;
	vector< set<int> > connections;
	
}*/
int main(){
	int numNodes,numEdges,u,v,node;
//	bool isCycle;

	vector< set<int> > graph;
	set<int> edges;
	vector<bool> visitedNodes;
	stack<int> s;
	cin>>numNodes;
	graph.resize(numNodes+1);
	visitedNodes.resize(numNodes+1);

	cin>>numEdges;
	if(numEdges != numNodes-1){
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0;i<numEdges;i++){
		cin>>v>>u;
		graph[v].insert(u);
		graph[u].insert(v);
	}

	s.push(1);
//	isCycle=false;

	while(!s.empty()){

		node=s.top();
		s.pop();

	/*	if(visitedNodes[node]){
			isCycle=true;
			break;
		}*/
		visitedNodes[node]=true;
		edges=graph[node];

		 for(set<int>::iterator it=edges.begin();it!=edges.end();it++){
			if(!visitedNodes[*it])
			 s.push(*it);
		 }
	}
	/*if(isCycle)
		cout<<"NO"<<endl;
	else{*/
		bool isTree=true;
		for(int i=1;i<=numNodes;i++){
			if(!visitedNodes[i]){
				isTree=false;
				break;
			}
		}
		if(isTree)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

//	}
	return 0;
}


