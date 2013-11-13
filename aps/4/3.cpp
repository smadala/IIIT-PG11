#include<iostream>
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
int max(int l,int r){
	if( l > r)
		return l;
	return r;
}

int height(struct node *root){
	int lh,rh;
	if( root == NULL)
		return 0;
	lh=height(root->l);
	rh=height(root->r);
	return  max(lh,rh)+1;
}

int diameter(struct node* root){
	int dl,dr,hl,hr;
	if(root == NULL)
		return 0;
	hl=height(root->l);
	hr=height(root->r);

	dl=diameter(root->l);
	dr=diameter(root->r);
	dl=max(dl,dr);

	return max(dl,hl+hr);

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
	cout << diameter(root)<<endl;
}
	
	
	
