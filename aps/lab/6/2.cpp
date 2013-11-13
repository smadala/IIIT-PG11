#include<iostream>
#include<stdlib.h>
using namespace std;
int t=0;
struct node {
	bool num;
	struct node **digit;
};
struct node* createNode(){
	struct node *temp;
	temp=new struct node();
	temp->digit=(struct node**)malloc(10*sizeof(struct node*));
	cout<< ++t<<" "<< sizeof(struct node)<<"  "<< sizeof(temp->digit)<<endl;
	return temp;
}
int main(){
	int t,n;
	bool mag=false,yes=true,final=true;
	string temp;

	struct node *head,*root;
	int index;
	cin>>t;
	while(t > 0){
		cin>>n;
		cout<<n<<" ";
		root=createNode();
		head=root;
		while( n > 0) {
			cin>>temp;
			cout<<temp<<endl;
			mag=false;
			final=true;
			if(yes){
			for( unsigned int i=0;i<temp.length();i++){
				index=temp[i]-'0';
				if(root->digit[index]==NULL){
					mag=true;
					root->digit[index]=createNode();
				}
				if(root ->num == true){
					final=false;
				}
				if(i == temp.length()-1){
					root->num=true;
				}
				root=root->digit[index];
			}
			root=head;
			yes=mag&&final;
			}
			n--;
		}
		if(yes)
		cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		yes=true;
		t--;
	}
	return 0;
}
