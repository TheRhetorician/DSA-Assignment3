#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	long long int data;
	struct Node *next;
	struct Node *prev;
}node;
void insert(long long int x, node* ptr)
{
	node* new = (node*)malloc(sizeof(node));
	new->data = x;
	new->next  = ptr;
	ptr->prev->next=new;
	new->prev = ptr->prev;
	ptr->prev = new;
}
int main()
{
	long long int x;
	char c;
	node *head = (node*)malloc(sizeof(node));
	head->prev = NULL;
	node *ptr = head;
	scanf("%lld",&x);
	do
	{
		ptr-> data= x;
		ptr-> next= (node*)malloc(sizeof(node));
		ptr->next-> prev = ptr;
		ptr= ptr->next;
	}while(scanf("%c%lld",&c,&x) != 1 && c!='\n');
	ptr->next = NULL;
	ptr = head;
	do
	{
		while(ptr-> data < x)
			ptr= ptr->next;
		insert(x,ptr);
	}while(scanf("%lld%c",&x,&c) != 1 && c!='\n');
	ptr = head;
	while(ptr->next!=NULL)
	{
		printf("%lld ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}