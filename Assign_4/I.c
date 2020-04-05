#include<stdio.h>
int N,arr[100000][2],r=0,max =0;
void swap(int a,int b)
{
	int x = arr[a][0];
	arr[a][0]= arr[b][0];
	arr[b][0]=x;
	x = arr[a][1];
	arr[a][1]= arr[b][1];
	arr[b][1]= x;
}
void Quicksort(int lo,int hi,int pivot)
{
	int a = lo;
	int b = pivot;
	while(lo!=hi)
	{
		if(arr[lo][r]>arr[pivot][r])
		{
			if(arr[hi][r]<arr[pivot][r])
				swap(lo,hi);
			else
				hi--;
		}
		else
			lo++;
	}
	if(arr[pivot][r] < arr[hi][r])
		swap(pivot,hi);
	if(a < pivot-1)
		Quicksort(a,pivot-2,pivot-1);
	if(b > pivot+1)
		Quicksort(pivot+1,b-1,b);
}
void check(int i,int count)
{
	if(i+1==N){
		if(count > max)
			max = count;
		return;
	}
	int l = arr[i][1];
	while(arr[++i][0] < l && i+1!=N)
		continue;
	check(i,count+1);
}
void print()
{
	for (int i = 0; i < N; ++i)
		printf("%d %d\n",arr[i][0],arr[i][1]);
}
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d",&arr[i][0],&arr[i][1]);
	Quicksort(0,N-2,N-1);
	r = 1;
	Quicksort(0,N-2,N-1);
	int i =0;
	while(arr[i][0] < arr[0][1])
		check(i++,1);
	printf("%d\n",max );
}
