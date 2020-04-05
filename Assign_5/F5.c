#include<stdio.h>
int N,arr[100000]={0};
void swap(int a,int b)
{
	int x = arr[a];
	arr[a]=arr[b];
	arr[b]=x;
}
void Quicksort(int lo,int hi,int pivot)
{
	int a = lo;
	int b = pivot;
	while(lo!= hi)
	{
		if(arr[lo]>arr[pivot])
		{
			if(arr[hi] < arr[pivot])
				swap(lo,hi);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[hi] > arr[pivot])
	{
		swap(hi,pivot);
		pivot= hi;
	}
	if(a <pivot-1)
		Quicksort(a,pivot-2,pivot-1);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b);
}
void sweets()
{
	int n = 1,sum=1;
	for (int i = 1; i < N; ++i)
	{
		if(arr[i]>arr[i-1])
			n+=1;
		sum+=n;
	}
	printf("%d\n",sum );
}
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d",&arr[i]);
	Quicksort(0,N-2,N-1);
	sweets();
}
