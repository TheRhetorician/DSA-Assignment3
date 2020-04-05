#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
void createlist(int n,struct node* head);
void rotate(int n,int r,struct node** head);
void rotateleft(int n,int r,struct node** head);
void display(struct node* head);
void main()
{
	int n,r;
	char ch;
	scanf("%d",&n);
	struct node* head = (struct node*)malloc(sizeof(struct node));
	createlist(n,head);
	scanf("%d",&r);
	scanf("%c",&ch);
	if(ch=='R')
	rotate(n,r,&head);
	else
	rotateleft(n,r,&head);
	display(head);
}
void createlist(int n,struct node* head)
{
	struct node* fnode;
	struct node* temp;
	int num,i;
	if(head==NULL)
	{
		printf("MEMORY LIMIT EXCEEDED");
	}
	else
	{
		scanf("%d",&num);
		head->data = num;
		head->prev = NULL;
		head->next = NULL;
		temp = head;
		for(i=1;i<n;i++)
		{
			fnode = (struct node*)malloc(sizeof(struct node));
			if(fnode==NULL)
			{
				printf("MEMORY LIMIT EXCEEDED");
				break;
			}
			else
			{
				scanf("%d",&num);
				fnode->data = num;
				fnode->next = NULL;
				temp->next = fnode;
				fnode->prev = temp;
				temp = temp->next;
			}
		}
	}
}
void rotate(int n,int r,struct node** head)
{
	r = r%n;
	//if(ch=='R')
	r = n-r;
	if(r==0)
	return;
	struct node* curr = *head;
	int count = 1; 
    while (count < r && curr != NULL) { 
        curr = curr->next; 
        count++; 
    } 
    if(curr==NULL)
    return;
    struct node* temp = curr;
    while(curr->next!=NULL)
    curr = curr->next;
    curr->next=*head;
    (*head)->prev = curr;
    *head = temp->next;
    (*head)->prev = NULL;
    temp->next=NULL;
}
void rotateleft(int n,int r,struct node** head)
{
	r=r%n;
	if(r==0)
	return;
	struct node* curr = *head;
	int count = 1; 
    while (count < r && curr != NULL) { 
        curr = curr->next; 
        count++; 
    } 
    if(curr==NULL)
    return;
    struct node* temp = curr;
    while(curr->next!=NULL)
    curr = curr->next;
    curr->next=*head;
    (*head)->prev = curr;
    *head = temp->next;
    (*head)->prev = NULL;
    temp->next=NULL;
}
void display(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
}
