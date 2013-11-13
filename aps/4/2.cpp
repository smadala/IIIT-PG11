#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node *root;
struct node{
	int data;
	int height;
	struct node* r;
	struct node* l;
};

void insert(int data){
	struct node *cur;
	struct node temp;
	cur=root;
	while(1){
		if(cur->data < data){
			if(cur->r == NULL){
				cur->r=new node;
				cur->r->data=data;
				break;
			}
			else
				cur=cur->r;
		}else{
			if(cur->l == NULL){
				cur->l=new node();
				cur->l->data=data;
				break;
			}
			else
				cur=cur->l;
		}
	}
}

void level_order(){
	struct node *cur;
	queue<node*> q;
	cur=root;
	if( cur ==NULL){
		return;
	}
	q.push(cur);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		cout<< cur->data <<" ";
		if(cur->l != NULL)
			q.push(cur->l);
		if(cur ->r != NULL)
			q.push(cur->r);
	}
	cout<<endl;

}
void in_order(){
	struct node *cur;
	stack<node*> s;
	cur=root;
	while(1){
		if(cur){
			s.push(cur);
			cur=cur->l;
		}
		else{
			if(s.empty()){
				cout<<endl;
				return;
			}
			else{
				cur=s.top();
				s.pop();
				cout<< cur->data <<" ";
				cur=cur->r;
			}
		}
	}
}

void post_order(){
	struct node *cur;
	stack<node*> s1;
	stack<node*> s2;
	if(root==NULL)
		return;
	cur=root;
	while(1){
			s2.push(cur);
			if(cur->l != NULL)
				s1.push(cur->l);
			if(cur->r != NULL)
				s1.push(cur->r);
			if(s1.empty())
				break;
			cur=s1.top();
			s1.pop();
	}
	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
	cout<<endl;
}

int main(){
	int n,data;
	cin>>n;
	if(n>0){
	cin>>data;
	root=new node();
	root->data=data;
	}

	for(int i=1;i<n;i++){
		cin>>data;
		insert(data);
	}
	in_order();
	post_order();
	level_order();
	return 0;
}
	
	
	
