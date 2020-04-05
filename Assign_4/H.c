#include<stdio.h>
#include<stdlib.h>
int N,M,arr[1000000],L,R,X;
void add_ar()
{
	for (int i = L; i <= R; ++i)
		arr[i]+=X;
}
void print()
{
	for (int i = 0; i < N; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d",&L,&R,&X);
		add_ar();
	}
	print();
}
