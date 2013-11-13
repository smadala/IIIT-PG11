#include<iostream>
#include<map>
using namespace std;
struct node{
	int size;
	map<int,node*> links;
};
int main(){
	map<int,node*> f;
	struct node *p=new node();
	f=p->links;
	cout<<sizeof(node)<<endl;
	return 0;
}
	
