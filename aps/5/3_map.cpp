#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

vector< map<int,int> > graph;
vector<bool> visited;
int side=8;
struct edge{
	int other;
	int weight;
};
bool greater1(struct edge *e1,struct edge *e2){
	return e1->weight > e2->weight;
}
int shortestLength(int s,int t){

	vector<int> dist;
	vector< edge*> edgeTo;
	struct edge* temp,*pre;
	map<int,int> adj;
	int soFar,other,w;

	cout<<"s- " << s<< "t- "<<t<<endl; 
	visited.resize(side*side);
	dist.resize(side*side,-1);
	dist[s]=0;
	visited[s]=true;
	adj=graph[s];

	for(map<int,int>::iterator it=adj.begin();it!=adj.end();it++){
		temp=new edge;
		temp->other=it->first;
		temp->weight=it->second;
		dist[temp->other]=it->second;
		edgeTo.push_back(temp);
	}


	make_heap(edgeTo.begin(),edgeTo.end());

	while(1){
		pop_heap(edgeTo.begin(),edgeTo.end());
		pre = edgeTo.back();
		edgeTo.pop_back();
		other=pre->other;
		if( other == t){
			return pre->weight;
		}
		visited[other]=true;
		adj=graph[other];
		
		for(map<int,int>::iterator it = adj.begin();it!=adj.end();it++){
			soFar=it->second+pre->weight;
			temp=new edge;
			temp->other=it->first;
			if( visited[it->first] || ( dist[it->first] != -1 && dist[it->first] <= soFar )){
				continue;
			}
			temp->weight=soFar;
			dist[it->first]=soFar;
			edgeTo.push_back(temp);
			push_heap(edgeTo.begin(),edgeTo.end());
		}
	}
	return -1;
}

			
			
	
int main(){
	int i,j,count,nodeNum,t,x1,x2,y1,y2;
	graph.resize(side*side);
	for(i=0;i<side;i++){
		for(j=0;j<side;j++){
			nodeNum=i*side+j;
			//q1
			if( i < side && j < side -1 ){ 
				graph[nodeNum][ ((i+1)*side)+j+2 ]=i*(i+1)+j*(j+2);
			}
			if( i < side -1 && j < side ){
				graph[nodeNum][ ((i+2)*side)+j+1 ]=i*(i+2)+j*(j+1);
			}
			//q2
			if( i > 0 && j < side -1){
				graph[nodeNum][ ((i-1)*side)+j+2 ]=i*(i-1)+j*(j+2);
			}
			if( i > 1 && j < side ){ 
				graph[nodeNum][ ((i-2)*side)+j+1 ]=i*(i-2)+j*(j+1);
			}
			//q3
			if( i > 0 && j > 1){
				graph[nodeNum][ ((i-1)*side)+j-2 ]=i*(i-1)+j*(j-2);
			}
			if( i > 1 && j > 0){
				graph[nodeNum][ ((i-2)*side)+j-1 ]=i*(i-2)+j*(j-1);
			}
			//q4
			if( i < side && j > 1){
				graph[nodeNum][ ((i+1)*side)+j-2 ]=i*(i+1)+j*(j-2);
			}
			if( i < side -1 && j > 0){
				graph[nodeNum][ ((i+2)*side)+j-1 ]=i*(i+2)+j*(j-1);
			}
		}
	}
	cin>>t;
	while( t-- > 0){
		cin>>x1>>y1>>x2>>y2;
		cout<<shortestLength(x1*side+y1,x2*side+y2)<<endl;
	}
	return 0;
}

