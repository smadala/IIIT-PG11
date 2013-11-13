#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;

struct edge{
	int other;
	int weight;
};

vector< vector<edge*> > graph;
vector<bool> visited;
vector<int> dist;
int side=8;
bool greater1(struct edge *e1,struct edge *e2){
	return dist[e1->other] > dist[e2->other];
	//return e1->weight > e2->weight;
}
int shortestLength(int s,int t){

	vector< edge*> edgeTo;
	struct edge *pre;
	vector<edge*> adj;
	int soFar,other;

	//cout<<"is- " << s<< "t- "<<t<<endl; 
	if(s==t)
		return 0;
	visited.resize(side*side);
	dist.resize(side*side,10000);
	dist[s]=0;
	visited[s]=true;
	adj=graph[s];

	for(vector<edge*>::iterator it=adj.begin();it!=adj.end();it++){
		dist[(*it)->other]=(*it)->weight;
		edgeTo.push_back(*it);
	}


	make_heap(edgeTo.begin(),edgeTo.end(),greater1);
		/*for(int i=0;i<edgeTo.size();i++){
			cout<< edgeTo[i]->other<<"-> "<<edgeTo[i]->weight<<endl;
		}*/

	while(1){
		pop_heap(edgeTo.begin(),edgeTo.end());
	//	cout<<endl;
		pre = edgeTo.back();
		edgeTo.pop_back();
		other=pre->other;
		//cout<<" ->"<<pre->other<<" ";
		if( other == t){
			edgeTo.clear();
			dist.clear();
			visited.clear();
			return dist[pre->other];
		}
		visited[other]=true;
		adj=graph[other];
		
		for(vector<edge*>::iterator it = adj.begin();it!=adj.end();it++){
			soFar=dist[other]+(*it)->weight;
			if( visited[(*it)->other] || ( /*dist[(*it)->other] != -1 &&*/ dist[(*it)->other] <= soFar )){
				continue;
			}
			dist[(*it)->other]=soFar;
			edgeTo.push_back(*it);
			push_heap(edgeTo.begin(),edgeTo.end());
		}
		make_heap(edgeTo.begin(),edgeTo.end(),greater1);
	/*	for(int i=0;i<edgeTo.size();i++){
			cout<< edgeTo[i]->other<<"-> "<<edgeTo[i]->weight<<endl;
		}*/
	}
	return -1;
}

			
			
	
int main(){
	int i,j,nodeNum,x1,x2,y1,y2/*num*/;
	struct edge *temp;
	graph.resize(side*side);
	for(i=0;i<side;i++){
		for(j=0;j<side;j++){
			nodeNum=i*side+j;
			//q1
			if( i < side-1 && j < side -2 ){ 
				temp=new edge;
				temp->other=((i+1)*side)+j+2;
				temp->weight=i*(i+1)+j*(j+2);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i+1*side)+j+2 ]=i*(i+1)+j*(j+2);
			}
			if( i < side -2 && j < side-1 ){
				temp=new edge;
				temp->other=((i+2)*side)+j+1;
				temp->weight=i*(i+2)+j*(j+1);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i+2*side)+j+1 ]=i*(i+2)+j*(j+1);
			}
			//q2
			if( i > 0 && j < side -1){
				temp=new edge;
				temp->other=((i-1)*side)+j+2;
				temp->weight=i*(i-1)+j*(j+2);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i-1*side)+j+2 ]=i*(i-1)+j*(j+2);
			}
			if( i > 1 && j < side-1){ 
				temp=new edge;
				temp->other=((i-2)*side)+j+1;
				temp->weight=i*(i-2)+j*(j+1);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i-2*side)+j+1 ]=i*(i-2)+j*(j+1);
			}
			//q3
			if( i > 0 && j > 1){
				temp=new edge;
				temp->other=((i-1)*side)+j-2;
				temp->weight=i*(i-1)+j*(j-2);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i-1*side)+j-2 ]=i*(i-1)+j*(j-2);
			}
			if( i > 1 && j > 0){
				temp=new edge;
				temp->other=((i-2)*side)+j-1;
				temp->weight=i*(i-2)+j*(j-1);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i-2*side)+j-1 ]=i*(i-2)+j*(j-1);
			}
			//q4
			if( i < side-1 && j > 1){
				temp=new edge;
				temp->other=((i+1)*side)+j-2;
				temp->weight=i*(i+1)+j*(j-2);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i+1*side)+j-2 ]=i*(i+1)+j*(j-2);
			}
			if( i < side -2 && j > 0){
				temp=new edge;
				temp->other=((i+2)*side)+j-1;
				temp->weight=i*(i+2)+j*(j-1);
				graph[nodeNum].push_back(temp);
				//graph[nodeNum][ (i+2*side)+j-1 ]=i*(i+2)+j*(j-1);
			}
		}
	}
	for(int i=0;i<64;i++){
		cout<<i<<endl;
		for(vector<edge*>::iterator it=graph[i].begin();it!=graph[i].end();it++){
			cout<<(*it)->other<<"-> "<< (*it)->weight<<" ";
		}
		cout<<endl;
	}
			
	while(1){
		if(scanf("%d",&x1)== EOF)
			break;

		scanf("%d",&y1);
		scanf("%d",&x2);
		scanf("%d",&y2);
		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		cout<<shortestLength(x1*side+y1,x2*side+y2)<<endl;
	}
	return 0;
}

