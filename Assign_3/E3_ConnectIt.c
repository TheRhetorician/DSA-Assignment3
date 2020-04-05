#include<stdio.h>
#include<stdlib.h>
int count,n,i,j=1;//n is number of nodes
struct node
{
	int info;
	struct node *next;
}*ptr,*start,*to,*from,*ahead,*behind;
void print()
{
	ptr = start;
	while(ptr != NULL)
	{
		printf("%d ",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}
int main()
{
	char c;
	ptr = (struct node*)malloc(sizeof(struct node));
	start=ptr;
do{
	scanf("%d%c",&ptr->info,&c);	
	if(c== '\n')
	ptr->next=NULL;
	else 
	{
		ptr->next = (struct node*)malloc(sizeof(struct node));
		ptr=ptr->next;
	}
	n++;
}while(c != '\n' );
from=start;
ahead=start;
to=start;
while(to->next != NULL)
	to=to->next;
behind=start;
while(count<=n-1)
{
	if(count%2==0)
	{
		behind=start;
		for(i=1;i<n-j;i++)
			behind=behind->next;
	}	
	ahead=from->next;
	if(n%2==0 && count==n-1)
	{
		from->next=to;
		to->next=NULL;
	}	
	else
	{
		if(count%2==0)
		{
			from->next=to;
			from=ahead;
			ahead=ahead->next;
		}
		else
		{
			to->next=from;
			to=behind;
		}		
	}		
	count++;
}
if(n%2 !=0)
	ahead->next=NULL;		
print();
	return 0;
}


