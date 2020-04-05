#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node* next;
}node;
int N,T,sum=0,exe[10000],arr[10000][3],final[10000],waiting[10000],curr_time=0,chk_t = 1,i=0,flag=0,j=0;
node* tail;
node* head;
void print();
node* Queue_enter(node* ptr)
{
	while(arr[i][1]==curr_time && i < N)
	{
		ptr->data = i;
		i++;
		ptr->next = (node*)malloc(sizeof(node));
		ptr = ptr->next;
		if(i == N)
			flag = 1;
	}
	return ptr;
}
void wait(int r)
{
	waiting[r]=(curr_time+1)-arr[r][1]-exe[r];
}
node* add_q(int r,node* ptr)
{
	ptr->data = r;
	ptr->next = (node*)malloc(sizeof(node));
	return ptr->next;
}
void time(node* ptr)
{
	if(chk_t < T)
	{
		if(--arr[ptr->data][2]<=0){
			chk_t=1;
			wait(ptr->data);
			final[j++]=arr[ptr->data][0];
			ptr = ptr->next;
		}
		else
			chk_t++;
	}
	else if(chk_t==T)
	{
		chk_t=1;
		final[j++]=arr[ptr->data][0];
		if(--arr[ptr->data][2]>0)
			tail = add_q(ptr->data,tail);
		wait(ptr->data);
		ptr = ptr->next;
	}
	curr_time++;
	if(!flag)
		tail=Queue_enter(tail);
	if(ptr->next==NULL)
		return;
	time(ptr);
}

void print()
{
	for (int k = 0; k < j; ++k)
		printf("%d ",final[k] );
	printf("\n");
}
int main()
{
	scanf("%d%d",&N,&T);
	node* ptr = (node*)malloc(sizeof(node));
	for (int i = 0; i < N; ++i){
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		exe[i]=arr[i][2];
	}
	head = ptr;
	tail = Queue_enter(ptr);
	time(ptr);
	for (int i = 0; i < N; ++i)
		sum+=waiting[i] ;
	printf("%d\n",sum);
	print();
}
