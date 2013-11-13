#include<stdio.h>
#include<stdlib.h>
struct data{
	char ch;
	struct data *next;
};
void insertHead(struct data **head,struct data **cur,char ch){
	struct data *node;
	node=(struct data *)malloc(sizeof(struct data));
	node->ch=ch;
	node->next=*head;
	*head=node;
	*cur=node;
}
void insertTail(struct data **tail,struct data **head,struct data **cur,  char ch){
	struct data *node;
	node=(struct data *)malloc(sizeof(struct data));
	node->ch=ch;
	if(*tail != NULL)
	(*tail)->next=node;
	else{
		*head=node;
		*cur=node;
	}
	*tail=node;
}
void insertCur(struct data **cur,char ch){
	struct data *node;
	struct data *temp;
	node=(struct data *)malloc(sizeof(struct data));
	node->ch=ch;
	temp=(*cur)->next;
	(*cur)->next=node;
	node->next=temp;
	*cur=node;
}

void printLine(struct data **head){
	while(*head != NULL){
		printf("%c",(*head)->ch);
		*head=(*head)->next;
	}
	printf("\n");
}


int main(){
	int h=0;
	struct data *head=NULL;
	struct data *tail=head;
	struct data *cur=head;
	char ch;
	
	while((ch=getchar()) == 'H' || ch == 'E');

	do{
		if( ch == 'H' ){
			h=1;
		}
		else if( ch == 'E' ){
			h=0;
		}
		else if ( h==1 ){
			insertHead(&head,&cur,ch);
			h=2;
		}
		else if (h == 2 ){
			insertCur(&cur,ch);
		}
		else 
			insertTail(&tail,&head,&cur,ch);
	}while((ch = getchar()) != '\n');
	printLine(&head);
	return 0;
}
