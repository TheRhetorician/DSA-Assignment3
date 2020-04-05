#include<stdio.h>
int N,arr[100001],pivot,flag=0;
void print();
void swap(int a,int b)
{
	flag=1;
	int x = arr[a];
	arr[a] = arr[b];
	arr[b] = x;
}
void Quicksort(int lo,int hi)
{
	while(lo!=hi)
	{
		if(arr[lo] > arr[pivot])
		{
			if(arr[hi]<arr[pivot])
				swap(lo,hi);
			else
			{
				if(hi!=pivot+1)
					hi--;
				else
					hi-=2;
			}
		}
		else
		{
			if(lo!=pivot-1)
				lo++;
			else
				lo+=2;
		}
	}
	if((arr[lo]>arr[pivot] && lo<pivot) || (arr[lo]<arr[pivot] && lo > pivot))
		swap(pivot,lo);
}
void print()
{
	for (int i = 0; i < N; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d",&arr[i]);
	scanf("%d",&pivot);
	Quicksort(0,N-1);
	if(flag)
		print();
	else
		printf("ALL SET\n");
}
