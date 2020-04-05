#include<stdio.h>
#include<stdlib.h>
long long int N,arr[100000];
int M,Q;
void swap(int a,int b)
{
	int x = arr[a];
	arr[a]=arr[b];
	arr[b]=x;
}
void Quicksort(int lo,int hi, int pivot)
{
	int a = lo;
	int b = pivot;
	while(lo!=hi)
	{
		if(arr[lo]>arr[pivot])
		{
			if(arr[hi]<arr[pivot])
				swap(lo,hi);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[hi]>arr[pivot])
	{
		swap(hi,pivot);
		pivot = hi;
	}
	if(a < pivot-1)
		Quicksort(a,pivot-2,pivot-1);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b);
}
void search(int x)
{
	int i;
	for (i = 0; i < M; ++i){
		if(arr[i]>x){
			if(arr[i]-x > x-arr[i-1])
				printf("%lld\n",x-arr[i-1] );
			else
				printf("%lld\n",arr[i]-x );
			return;
		}
	}
	printf("%lld\n",x-arr[i-1] );
}
int main()
{
	long long int input;
	scanf("%lld%d",&N,&M);
	for (int i = 0; i < M; ++i)
		scanf("%lld",&arr[i]);
	Quicksort(0,M-2,M-1);
	scanf("%d",&Q);
	for (int i = 0; i < Q; ++i)
	{
		scanf("%lld",&input);
		search(input);
	}
}
