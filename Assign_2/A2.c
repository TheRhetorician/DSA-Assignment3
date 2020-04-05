#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	long long int data;
	struct Node *next;
	struct Node *prev;
}node;
int main()
{
	long long int x,count=0;
	char y;
	scanf("%lld",&x);
	node* head = (node*)malloc(sizeof(node));
	node* ptr = head;
	head->prev = NULL;
	do
	{
		count++;
		ptr-> data = x;
		ptr->next = (node*)malloc(sizeof(node));
		ptr->next->prev = ptr;
		ptr = ptr->next; 
	}while(scanf("%c%lld",&y,&x)!=1 && y!='\n' );
	ptr->next = NULL;
	scanf("%lld",&x);
	scanf(" %c",&y);
	ptr =head;
	x = x % count;
	if(y == 'R')
	{
		count = count - x;
		for (int i = 0; i < count; ++i)
			ptr = ptr->next;
		while(ptr->next != NULL){
			printf("%lld ",ptr->data );
			ptr = ptr->next;
		}
		ptr = head;
		for (int i = 0; i < count; ++i){
			printf("%lld ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < x; ++i)
			ptr = ptr->next;
		while(ptr->next != NULL){
			printf("%lld ",ptr->data );
			ptr = ptr->next;
		}
		ptr = head;
		for (int i = 0; i < x; ++i){
			printf("%lld ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}