#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min=100000000;
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *top = NULL;

int push(char arr[],int x)
{
	int n = strlen(arr);
	int i=x+1,sum=0;
	while(i<n)
	{
		sum = sum*10 + (arr[i]-'0');
		i++;
	}
	node* tmp;
	tmp = malloc(sizeof(node));
	if(tmp!=NULL)
	{
		tmp->data = sum;
		tmp->next = top;
		top = tmp;
	}
	if(sum<min)
	min = sum;
	return sum;
}

int pop()
{
	int b;
	node *tmp;
	tmp = top;
	top = top->next;
	b = tmp->data;
	free(tmp);
	return b;
}

int peek()
{
	int a = top->data;
	return a;
}

int getMin()
{
	min = 100000;
	node* ptr = top;
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
	int n;
	char arr[100];
	scanf("%d\n",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%[^\n]%*c", arr);
		//strcat(arr,'\0');
		if(strncmp(arr,"push",4)==0)
		{
			int a = push(arr,4);
			printf("OK Pushed %d\n",a);
			//printf("inside");
		}
		else if(strncmp(arr,"pop",3)==0)
		{
			int b = pop();
			printf("OK Popped %d\n",b);
		}
		else if(strncmp(arr,"peek",4)==0)
		{
			int c = peek();
			printf("%d\n",c);
		}
		else if(strncmp(arr,"getMin",6)==0)
		{
			int d = getMin();
			printf("%d\n",d);
		}
	}
}
