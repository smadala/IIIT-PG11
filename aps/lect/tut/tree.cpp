#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
struct node *root;


struct node* newnode(int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
return temp;
}

void maketree(struct node * root,struct node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			maketree(root->left,temp);
		else
			root->left=temp;
	}
	else
	{
		
		if(root->right!=NULL)
			maketree(root->right,temp);
		else
			root->right=temp;
	}
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<"  ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"  ";
	}
}
int height(struct node * root)
{
	if(root==NULL)
		return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	return (max(lh,rh)+1);
}

void print_level(int level,struct node * root)
{
	if(level==0)
		cout<<root->data<<"  ";
	else
	{
		if(root->left!=NULL)
			print_level(level-1,root->left);
		if(root->right!=NULL)
			print_level(level-1,root->right);
	}
}
void levelorder(struct node* root)
{
	int h=height(root);
	for(int i=0;i<h;i++)
	{
		print_level(i,root);
	}

}
int no_of_leaf_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	
	int ll=no_of_leaf_nodes(root->left);
	int rr=no_of_leaf_nodes(root->right);
	
	return (ll+rr);
}

int total_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
	int ll=total_nodes(root->left);
	int rr=total_nodes(root->right);

	return ll+rr+1;
}

int non_leaf_nodes(struct node * root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	int ll=non_leaf_nodes(root->left);
	int rr=non_leaf_nodes(root->right);

	return ll+rr+1;
}

int main()
{
	int val;
	struct node *temp;
	while(true)
	{
		cin>>val;
		if(val==-1)
			break;
		if(root==NULL)
			root=newnode(val);
		else
		{
			temp=newnode(val);
			maketree(root,temp);
		}
	}

	cout<<"Preorder is : ";
	preorder(root);
	cout<<"\n";	
	cout<<"Inorder is : ";
	inorder(root);
	cout<<"\n";
	cout<<"Postorder is : ";
	postorder(root);
	cout<<"\n";
	
	cout<<"height is: "<<height(root)<<"\n";
	cout<<"level order is : ";
	levelorder(root);
	cout<<"\n";
	cout<<"number of leaf nodes are: "<<no_of_leaf_nodes(root)<<endl;

	cout<<"number of non_leaf_nodes are :"<<non_leaf_nodes(root)<<endl;

	cout<<"number of total nodes are :"<<total_nodes(root)<<endl;

return 0;
}
