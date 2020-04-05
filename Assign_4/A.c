#include<stdio.h>
#include<stdlib.h>
int N,arrx[100000][3],S,min = 100000;
double slope[10000][2];
void swap(int a,int b,double arr[][2])
{
	double x = arr[a][0];
	arr[a][0] = arr[b][0];
	arr[b][0] = x;
	x = arr[a][1];
	arr[a][1] = arr[b][1];
	arr[b][1] = x;
}
void quicksort(int pivot,int lo,int hi,double arr[][2])
{
	int a = lo;
	int b = pivot;
	while(lo != hi)
	{
		if(arr[lo][1] > arr[pivot][1]){
			if(arr[hi][1] < arr[pivot][1])
				swap(lo,hi,arr);
			else
				hi--;
		}
		else
			lo++;
	}
	if (arr[hi][1]>=arr[pivot][1]){
		swap(hi,pivot,arr);
		pivot = hi;
	}
	if(a < pivot-1)
		quicksort(pivot-1,a,pivot-2,arr);
	if(b > pivot+1)
		quicksort(b,pivot+1,b-1,arr);
}
void print()
{
	int i;
	for (i = 0; i < N; ++i)
		if(slope[i][1]>0)
			break;
	for (int j = i; j < N; ++j)
	{
		int r = slope[j][0];
		printf("%d ",r );
	}
	for (int j = 0; j < i; ++j)
	{
		if(slope[j][0]==0)
			continue;
		int r = slope[j][0];
		printf("%d ",r );
	}
	printf("\n");
}
int main()
{
	int a;
	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf("%d%d%d",&arrx[i][0],&arrx[i][1],&arrx[i][2]);
		if(arrx[i][2] < min)
		{
			min = arrx[i][2];
			S = i;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if(S==i)
			continue;
		slope[i][0]=arrx[i][0];
		if(arrx[i][1]!=arrx[S][1])
			slope[i][1]=(arrx[i][2]-arrx[S][2])/(double)(arrx[i][1]-arrx[S][1]);
		else
			slope[i][1]=100000;
	}
	quicksort(N-1,0,N-2,slope);
	print();
}
