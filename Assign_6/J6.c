#include<stdio.h>
int N, arr[10000][3],curr_time=-1,Q[10000],top=-1,a,check[10000],final[10000];
void push(int i)
{
	Q[++top]=i;
}
int pop()
{
	if(top==-1)
		return -1;
	return Q[top--];
}
void swap(int i,int j)
{
	int x = arr[i][0];
	arr[i][0]=arr[j][0];
	arr[j][0]=x;
	x = arr[i][1];
	arr[i][1]=arr[j][1];
	arr[j][1] = x;
	x = arr[i][2];
	arr[i][2]=arr[j][2];
	arr[j][2] = x;
}
void Quicksort(int lo,int hi,int pivot,int r)
{
	int a = lo;
	int b = pivot;
	while(lo!=hi)
	{
		if(arr[lo][r]>arr[pivot][r])
		{
			if(arr[hi][r] < arr[pivot][r])
				swap(lo,hi);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[hi][r]>arr[pivot][r])
	{
		swap(hi,pivot);
		pivot = hi;
	}
	if(a < pivot-1)
		Quicksort(a,pivot-2,pivot-1,r);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b,r);
}
void enter_Q()
{
	int i = N,flag = 0;
	while(--i>=0)
	{
		if(arr[i][1]==curr_time+1)
		{
			flag = 1;
			push(i);
		}	
	}
}
void time()
{
	curr_time++;
	a = pop();
	if(a==-1)
		return;
	if(--arr[a][2] <= 0)
		final[a]=curr_time+1;
	else
		push(a);
	if(check[curr_time+1]!=0)
		enter_Q();
	time();
}
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	Quicksort(0,N-2,N-1,0);
	Quicksort(0,N-2,N-1,1);
	for (int i = 0; i < N; ++i)
		check[arr[i][1]]++;
	enter_Q();
	time();
	for (int i = 0; i < N; ++i)
		printf("%d %d \n",arr[i][0],final[i]);
}
