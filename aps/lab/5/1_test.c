#include<stdio.h>
#include<stdlib.h>
struct node{
	char ch;
	struct node *next;
};
void insert(struct node **tail,struct node **head, char ch){
	struct node *new;
	new=(struct node * )malloc(sizeof(struct node));
	new->ch=ch;
	printf("%c\n",ch);
	if(*tail != NULL){
		(*tail)->next=new;
	}
	else{
		*head =new;
	}
		*tail = new;

}
void printList(struct node **head){
	while(*head != NULL){
		printf("%c",(*head)->ch);
		*head=(*head)->next;
	}
	printf("\n");
}
int main(){
	char ch;
	struct node *tail=NULL;
	struct node *head=NULL;

	while((ch=getchar())!='\n'){
		insert(&tail,&head,ch);
	}
	printList(&head);
}
