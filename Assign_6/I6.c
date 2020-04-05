#include <stdio.h>
#include <stdlib.h>
int top = 10;
int stack1[20];
int top1 = -1;


void push1(int x)
{
        stack1[++top1] = x;
}
 
int pop1()
{
        return stack1[top1--];
}


struct node
{
	char ch;
	struct node *next;
	struct node *prev;
}  *stack[11];
typedef struct node node;
 
void push(node *str)
{
	if (top <= 0)
	printf("Stack is Full ");
	else
	{
		stack[top] = str;
		top--;
	}
}
 
node *pop()
{
	node *exp;
	if (top >= 10)
		printf("Stack is Empty ");
	else
		exp = stack[++top];
	return exp;
}
void convert(char exp[])
{
	node *op1,  *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= '0'&& exp[i] <= '9')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = NULL;
		temp->prev = NULL;
		push(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||
exp[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}
}
 
void display(node *temp)
{
	if (temp != NULL)
	{
		display(temp->prev);
		printf("%c", temp->ch);
		display(temp->next);
	}
}
 
void main()
{
	char exp[50];
	//clrscr();
	//printf("Enter the postfix expression :");
	scanf("%s", exp);
	char *e;
    int n1,n2,n3,num;
    e = exp;
    while(*e != '\0')
    {
        if(*e>='0' && *e<='9')
        {
            num = *e - 48;
            push1(num);
        }
        else
        {
        	n1 = pop1();
            n2 = pop1();
            switch(*e)
            {
            	case '+':
                {
                    n3 = n1 + n2;
                    break;
                }
                case '-':
                {
                        n3 = n2 - n1;
                        break;
                }
                case '*':
                {
                        n3 = n1 * n2;
                        break;
                }
                case '/':
                {
                        n3 = n2 / n1;
                        break;
                }
            }
			push1(n3);
	    }
		e++;
	}
    printf("%d\n",pop1());
	convert(exp);
	//printf("\nThe Equivalant Infix expression is:");
	display(pop());
	//printf("\n\n");
	//getch();
}
