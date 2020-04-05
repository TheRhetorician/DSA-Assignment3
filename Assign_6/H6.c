// C++ program to find maximum rectangular area in 
// linear time 
#include<stdio.h>
#include<stdlib.h> 

int stack[300];
int top=-1;

void push(int x)
{
	if(top<300)
	stack[++top]=x;
}

void pop()
{
	if(top>=0)
	top--;
}

int getMaxArea(int hist[], int n) 
{ 
	// Create an empty stack. The stack holds indexes 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights. 
	int tp;
	int max_area = 0; // Initialize max area  
	int area_with_top; // To store area with top bar 
					// as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0; 
	while (i < n) 
	{ 
		// If this bar is higher than the bar on top 
		// stack, push it to stack 
		if (top<0 || hist[stack[top]] <= hist[i]) 
		push(i++); 

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index' 
		else
		{ 
			tp = stack[top]; // store the top index 
			pop(); // pop the top 

			// Calculate the area with hist[tp] stack 
			// as smallest bar 
			area_with_top = hist[tp] * ((top<0) ? i : 
								i - stack[top]- 1); 

			// update max area, if needed 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		} 
	} 

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (top>=0) 
	{ 
		tp = stack[top]; 
		pop(); 
		area_with_top = hist[tp] * ((top<0) ? i : 
								i - stack[top] - 1); 

		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 

	return max_area; 
} 

// Driver program to test above function 
int main() 
{ 
	int n;
	scanf("%d",&n);
	int hist[n];
	int i=0;
	for(i=0;i<n;i++)
	scanf("%d",&hist[i]);
	int ans = getMaxArea(hist, n);
	printf("Maximum area is %d",ans); 
	return 0; 
} 

