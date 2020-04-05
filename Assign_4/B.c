#include<stdio.h>
#include<stdlib.h>
int arr[100001][2];
int N,E;
void swap(int a,int b)
{
	int x = arr[a][0];
	arr[a][0]=arr[b][0];
	arr[b][0]=x;
	x = arr[a][1];
	arr[a][1]=arr[b][1];
	arr[b][1]=x;
}
void Quicksort(int lo,int hi, int pivot)
{
	int a = lo;
	int b = pivot;
	while(lo!=hi)
	{
		if(arr[lo][1] > arr[pivot][1])
		{
			if(arr[hi][1] < arr[pivot][1])
				swap(lo,hi);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[hi][1] > arr[pivot][1]){
		swap(hi,pivot);
		pivot = hi;
	}
	if(a < pivot-1)
		Quicksort(a,pivot-2,pivot-1);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b);

}
void aggregate(int i)
{
	while(arr[i++][1]<E && i<N)
		arr[i][1]+=arr[i-1][1];
	if(arr[i-1][1] < E){
		printf("NO CHANCE\n");
		exit(0);
	}
	else
		for (int j = 1; j < i; ++j)
			printf("%d ",arr[j][0]);
	printf("\n");
}
int main()
{
	scanf("%d",&N);
	int input;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d",&input);
		arr[i][0]=i;
		arr[i][1]=input;
	}
	Quicksort(1,N-2,N-1);
	scanf("%d",&E);
	aggregate(0);
}
