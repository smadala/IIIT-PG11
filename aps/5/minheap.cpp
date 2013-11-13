#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
struct node{
	int o;
	int w;
};
bool greater1(struct node *e1,struct node *e2){
/*	if( e1 == NULL || e2 ==NULL){
		return false;
	}*/
	return e1->w > e2->w;
}
int main(){
	vector<node*> dist;
	struct node *temp;
//	dist.resize(10);
	for( int i=0; i < 10;i++){
		temp=new node;
		temp->o=i;
		temp->w=(10-i)*10;
	//	dist[i]=temp;
		dist.push_back(temp);
	//	push_heap(dist.begin(),dist.end());
	}
	make_heap(dist.begin(),dist.end(),greater1);
	for(vector<node*>::iterator it=dist.begin();it!=dist.end();it++){
		cout<<"o-"<<(*it)->o<<"w-"<<(*it)->w<<endl;
	}

/*	for(unsigned  i=0;i<dist.size();i++){
 		cout<< "o-"<< dist[i]->o << "w-"<< dist[i]->w <<endl;
	}*/
		
	/*for(int i=0;i<10;i++){
		cout<<"o-"<<dist[i]->o<<"w-"<<dist[i]->w<<endl;
	}*/
	for(int i=0;i<4;i++){
	pop_heap(dist.begin(),dist.end());
	cout<<dist.back()->w<<endl;
	dist.pop_back();
	}
	/*pop_heap(dist.begin(),dist.end());
	cout<<dist.back()->w<<endl;
	dist.pop_back();*/
	for(vector<node*>::iterator it=dist.begin();it!=dist.end();it++){
		cout<<"o-"<<(*it)->o<<"w-"<<(*it)->w<<endl;
	}
	/*for(int i=0;i<10;i++){
		cout<<"o-"<<dist[i]->o<<"w-"<<dist[i]->w<<endl;
	}*/
	return 0;	
}
