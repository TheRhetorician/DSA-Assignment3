#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* next;
	int data;
};
typedef struct Node node;
node* merge(node* a,node* b)
{
	node* result=NULL;
	if(a==NULL)
		return (b);
	else if(b==NULL)
		return (a);
	if(a->data<=b->data){
		result=a;
		result->next=merge(a->next,b);
	}
	else{
		result=b;
		result->next=merge(a,b->next);
	}
	return (result);
}
void split(node* source, node** front, node** back)
{
	node* slow;
	node* fast;
	slow=source;
	fast=source->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*front=source;
	*back=slow->next;
	slow->next=NULL;
}
void sort(node** startRef)
{
	node* start=*startRef;
	node* a;
	node* b;
	if(start==NULL||start->next==NULL)
		return;
	split(start,&a,&b);
	sort(&a);
	sort(&b);
	*startRef=merge(a,b);
}
int main()
{
	node* ptr=(node*)malloc(sizeof(node));
	node* start;
	start=ptr;
	int i,j,x; char ch='a';
	while(ch!='\n'){
		scanf("%d%c",&x,&ch);
		ptr->data=x;
		ptr->next=(node*)malloc(sizeof(node));
		ptr=ptr->next;
	}
	ptr=start;
	while(ptr->next->next!=NULL)
		ptr=ptr->next;
	ptr->next=NULL;
	sort(&start);
	ptr=start;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
