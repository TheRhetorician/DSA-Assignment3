#include<stdio.h>
#include<stdlib.h>
int N,M,L,U,V,A,B,K,arc[10000],fuel[1000000]={0},mileage[100000]={0},sp = -1,ep = -1,sum=0;
void swap(int a , int b,int arr[])
{
	int x = arr[a];
	arr[a]=arr[b];
	arr[b] = x;
}
void find()
{
	for (int i = 0; i < M; ++i)
	{
		if(arc[i]==U){
			sp = i;
			break;
		}
	}
	if(sp == -1)
	{
		printf("NOT POSSIBLE\n");
		exit(0);
	}
	for (int i = sp; i < M; ++i)
	{
		if(arc[i]>=V){
			ep = i;
			break;
		}
	}
}
void Quicksort(int lo,int hi,int pivot,int arr[])
{
	int a = lo;
	int b = pivot;
	while(lo!=hi)
	{
		if(arr[lo]>arr[pivot]){
			if(arr[hi] < arr[pivot])
				swap(lo,hi,arr);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[hi] > arr[pivot])
	{
		swap(hi,pivot,arr);
		pivot = hi;
	}
	if(a < pivot-1)
		Quicksort(a,pivot-2,pivot-1,arr);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b,arr);
}
int cost(int s,int e)
{
	for (int i = 0; i < L; ++i)
		if(mileage[i]>=e-s)
			return K*fuel[i];
	printf("NOT POSSIBLE\n");
	exit(0);
}
int main()
{
	scanf("%d%d%d",&N,&M,&L);
	scanf("%d%d%d%d%d",&U,&V,&A,&B,&K);

	for (int i = 0; i < M; ++i)
		scanf("%d",&arc[i]);
	Quicksort(0,M-2,M-1,arc);

	for (int i = 0; i < L; ++i)
		scanf("%d",&fuel[i]);
	Quicksort(0,L-2,L-1,fuel);

	for (int i = 0; i < L; ++i)
		mileage[i]=A*fuel[i]+B;
	find();
	for (int i = sp; i < ep ; ++i)
		sum+=cost(arc[i],arc[i+1]);
	printf("%d\n",sum );
}
