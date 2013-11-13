#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *p;
	struct node *l;
	struct node *r;
};

struct node* createNewNode(struct node *root,int data){
	struct node *temp;
	temp =new struct node();
	temp->p=root;
	temp->data=data;
	return temp;
}

int main(){
	int num,temp;
	struct node *root;
	cin>>num;
	if ( num > 0)
	{
		root=new struct node();
		root->p=NULL;
		cin>>root->data;
	}
	bool ins=false;
	struct node *head=root;
	for(int i=0;i<num;i++){
		cin >>temp;
		while(!ins)
		{
			if( root->data <= temp ){
				if(root->l == NULL){
				root->l=createNewNode(root,temp);
				ins=true;
				}else{
					root=root->l;
				}
			}
			else if(root->p != NULL && root->p->data >= temp){
				if( root->r == NULL ){
					root->r=createNewNode(root,temp);
					ins=true;
				}else{
					root=root->r;
				}
			}
			else if(root->p !=NULL && root->p->data < temp){
				if(root->p->r != NULL){
					root=root->p->r;
				}else{
					root->p->r=createNewNode(root->p,temp);
					ins=true;
				}
			}else if(root->p == NULL){
				if(root->r == NULL)
				{
					root->r=createNewNode(root,temp);
					ins=true;
				}else{
					root=root->r;
				}
			}
		}
		ins=false;
	}
	
	}


}
