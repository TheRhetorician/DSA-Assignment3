#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	long long int data;
	struct Node *next;
}node;
int count = 0;
node* attach(node*ptr)
{
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	return ptr;
}
void print(node* ptr)
{
	while(ptr!= NULL)
	{
		printf("%lld ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int main()
{
	long long int input;
	char c;
	node *head = (node*)malloc(sizeof(node));
	node* prev;
	node *ptr = head;
	while(scanf("%lld%c",&input,&c)!=1 && c!='\n')
	{
		count++;
		ptr->data = input;
		ptr->next = (node*)malloc(sizeof(node));
		prev = ptr;
		ptr=ptr->next;
	}
	node*top = head;
	ptr->data = input;
	ptr->next = NULL;
	int i = 0;
	while(i++ < count/2)
	{
		node*info = head->next;
		head->next = ptr;
		ptr->next = info;
		prev->next =NULL;
		head = info;
		prev = attach(top);
		ptr = prev->next;
	}
	print(top);
}
