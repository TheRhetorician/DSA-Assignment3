#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[200];
char arr[200];
int top=-1;

void push(char ch)
{
	if(top<200)
	{
		stack[++top]=ch;
	}
}

void pop()
{
	if(top>=0)
	{
		top--;
	}
}

void main()
{
	scanf("%s",arr);
	int n = strlen(arr);
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]=='(' || arr[i]=='{' || arr[i]=='[')
		{
			push(arr[i]);
			continue;
		}
		else if(arr[i]==')' || arr[i]=='}' || arr[i]==']')
		{
			if(stack[top]=='(' && arr[i]==')')
			{
				pop();
			}
			else if(stack[top]=='{' && arr[i]=='}')
			{
				pop();
			}
			else if(stack[top]=='[' && arr[i]==']')
			{
				pop();
			}
			else
			{
				printf("No");
				return;
			}
		}
	}
	printf("Yes");
}
