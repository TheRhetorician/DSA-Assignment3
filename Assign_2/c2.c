#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char input[20];
typedef struct Node{
	long long int data;
	struct Node *next;
}node;
node* head;
void add(node* ptr,long long int x)
{
	node*new = (node*)malloc(sizeof(node));
	new->data=x;
	new->next = NULL;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return;
}
void insert(long long int x, int pos,node* ptr)
{
	head = ptr;
	node* insert = (node*)malloc(sizeof(node));
	insert->data = x;
	if (pos == 1){
		insert->next = ptr;
		head = insert;
	}
	else
	{
		node* prev = ptr;
		for (int i = 1; i < pos; ++i)
		{
			prev = ptr;
			ptr= ptr->next;
		}
		insert->next = ptr;
		prev->next = insert;
	}
}
int remove_n(long long int x,node* ptr)
{
	int count = 0;
	node* ref=NULL;
	node* prev;
	if(ptr->data == x){
		head = ptr->next;
		count =1;
		free(ptr);
	}
	else{
		while(ptr->next != NULL )
		{
			if(ptr->next->data==x)
			{
				count = 1;
				node*remove = ptr->next;
				if(ptr->next->next != NULL)
					ptr->next = ptr->next->next;
				else
					ptr->next = NULL;
				free(remove);
				break;
			}
			ptr = ptr->next;
		}
	}
	while(ptr->next != NULL){
		if(ptr->next->data == x){
			ref = ptr->next;
			prev = ptr;
		}
		ptr = ptr->next;
	}
	if(ref != NULL)
	{
		prev->next = ref->next;
		free(ref);
	}
	if(count == 0)
	{
		printf("Element not found\n");
		return 1;
	}
	return 0;
}
node* reverse(node* ptr)
{
	if(ptr->next == NULL){
		head = ptr;
		return ptr;
	}
	node* prev = reverse(ptr->next);
	prev->next =ptr;
	ptr->next = NULL;
	return ptr;
}
long long int fetch(int x,node* ptr)
{
	for (int i = 1; i < x; ++i)
		ptr=ptr->next;
	return ptr->data;
}
void print(node* ptr)
{
	while(ptr->next != NULL){
		printf("%lld ",ptr->data );
		ptr = ptr->next;
	}
	printf("%lld\n",ptr->data);
}
int main()
{
	int N,y;
	long long int x;
	scanf("%d",&N);
	head = (node*)malloc(sizeof(node));
	for (int i = 0; i < N; ++i)
	{
		scanf("%s",input);
		if(strcmp("add",input)==0)
		{
			scanf("%lld",&x);
			if(i==0)
			{
				head->data = x;
				head->next = NULL;
			}
			else
				add(head,x);
			print(head);
			continue;
		}
		else if(strcmp("reverse",input)==0)
		{
			node*x = reverse(head);
			print(head);
			continue;
		}
		else if(strcmp("remove",input)==0)
		{
			scanf("%lld",&x);
			if(!remove_n(x,head))
				print(head);
			continue;
		}
		else if(strcmp("insert",input)==0)
		{
			scanf("%lld%d",&x,&y);
			insert(x,y,head);
			print(head);
			continue;
		}
		else if(strcmp("fetch",input)==0)
		{
			scanf("%d",&y);
			printf("%lld\n",fetch(y,head));
		}
	}
}