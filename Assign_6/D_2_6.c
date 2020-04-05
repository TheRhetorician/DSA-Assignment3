#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}node;
int flag = 0;  
node* head;
node* push(node* ptr,int info)
{
	ptr->data = info;
	ptr->next = (node*)malloc((sizeof(node)));
	ptr->next->prev = ptr;
	ptr = ptr->next;
	printf("OK PUSHED %d\n",info );
	flag = 0;
	return ptr;
}
int peek(node* ptr)
{
	return ptr->prev->data;
}
node* pop(node* ptr)
{
	if(ptr->prev == NULL)
		flag = 1;
	printf("OK POPPED %d\n",ptr->prev->data);
	ptr->prev->next = NULL;//(node*)malloc(sizeof(node));
	return ptr->prev;
}
int getMin()
{
	int min = 100000;
	node* ptr = head;
	while(ptr->next != NULL)
	{
		if(ptr->data < min)
			min = ptr->data;
		ptr=ptr->next;
	}
	return min;
}
int main()
{
	int N,input;
	char a[10];
	scanf("%d",&N);
	head = (node*)malloc(sizeof(node));
	node* ptr = head;
	head->prev = NULL;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s",a);
		if(!strcmp(a,"push")){
			scanf("%d",&input);
			ptr = push(ptr,input);
		}
		else if(!strcmp(a,"pop"))
			ptr = pop(ptr);
		else if(!strcmp(a,"getMin"))
			printf("%d\n",getMin());
		else if(!strcmp(a, "peek"))
			printf("%d\n",peek(ptr) );
	}
}
