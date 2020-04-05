#include<stdio.h>
#include<stdlib.h>
struct Node{
	int id,arrival,time;
};
typedef struct Node process;
process queue[100000];
process arr[1000000];
int ansArr[1000000];
int front=-1,rear=-1;
int isEmpty()
{
	if(front==-1 || front>rear)
		return 1;
	else 
		return 0;
}
void enqueue(process ele)
{
	if((rear+1)%1000000!=front)
		rear=(rear+1)%1000000;
	if(front==-1)
		front=0;
	queue[rear]=ele;
}
void dequeue()
{
	process item;
	if(!isEmpty()){
		item=queue[front];
		front=(front+1)%100000;
	}
}
int main()
{
	int i,j,n,k=0,t,ans=0;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++)
		scanf("%d %d %d",&arr[i].id,&arr[i].arrival,&arr[i].time);
	int currTime=0,totalTime=0;
	for(i=0;i<n;i++){
		if(arr[i].arrival<=currTime)
		{
			ansArr[k++]=arr[i].id;
			enqueue(arr[i]);
		}
		else
			break;
	}
	while(!isEmpty() || i<n)
	{
		currTime++;
		totalTime++;
		ans=ans+rear-front;
		queue[front].time=queue[front].time-1;
		if(queue[front].time==0){
			dequeue();
			currTime=0;
		}
		else if(currTime%t==0){
			ansArr[k++]=queue[front].id;
			enqueue(queue[front]);
			dequeue();
			currTime=0;
		}
		while(i<n){
			if(arr[i].arrival<=totalTime)
			{
				ansArr[k++]=arr[i].id;
				enqueue(arr[i++]);
			}
			else
				break;
		}		
	}
	printf("%d\n",ans);
	for (i = 0; i < k; ++i)
	{
		printf("%d ",ansArr[i]);
	}
	printf("\n");
}
