#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

int NodeStatus[100000];


using namespace std;

int bfsq[100000];
int front;
int rear;

void DFS(vector <vector<int> > &edges,int N,int curNode,int parentNode)
{
    int i;
	if(NodeStatus[curNode])
		return;

	NodeStatus[curNode]=1;

	for(i=0;i<(int)edges[curNode].size();i++)
	{
			if(edges[curNode][i]!=parentNode)
			DFS(edges,N,edges[curNode][i],curNode);
	}
}

void BFS(vector <vector<int> > &edges)
{
	int i,curNode;
	front=0;
	rear=1;

	while(front!=rear)
	{
		curNode=bfsq[front];
		front++;
		NodeStatus[curNode]=1;
				
		for(i=0;i<(int)edges[curNode].size();i++)
		{
			if(NodeStatus[edges[curNode][i]]==0)
			{
				rear++;
				bfsq[rear]=edges[curNode][i];
			}
		}
		NodeStatus[curNode]=2;
	}
}

int main()
{
	int N,M,Q;
	int v1,v2;
	int i;
	int k=0;
	int comps=0;	

	vector<vector<int> > edges;

	edges.resize(100000);
	
	scanf("%d",&Q);

	while(Q>0)
	{


		scanf("%d",&N);
		scanf("%d",&M);

		for(i=0;i<N+1;i++)
		{
			edges[i].clear();
			NodeStatus[i]=0;
		}


		for(i=0;i<M;i++)
		{
			scanf("%d",&v1);
			scanf("%d",&v2);
			edges[v1].push_back(v2);
			edges[v2].push_back(v1);
		}

		k=0;comps=0;

		while(1)
		{
	
			for(i=k;i<N;i++)
			{
				if(NodeStatus[i]==0)
					break;
			}	

			k=i;

			if(i==N)
				break;

			bfsq[0]=i;
			BFS(edges);
			//DFS(edges,N,i,i);
			comps++;
		}	

		printf("%d\n",comps);

		Q--;
	}
		return 0;
}

