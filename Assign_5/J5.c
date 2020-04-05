#include<stdio.h>
#include<stdlib.h>
int N;
long long int arr[3000000],K,pivot;
void binary(int sp,int ep)
{
	if(sp ==ep)
		return;
	int x = (sp+ep)/2;
	if(arr[x]==K)
	{
		printf("YES\n");
		printf("%d\n",x);
		exit(0);
	}
	else if(K<arr[x] && arr[x]-1 < arr[x])
		binary(sp,x);
	else if(K<arr[x] && arr[x]-1 > arr[x])
		binary(x,ep);
	else if(K > arr[x] && arr[x]+1 > arr[x])
		binary(x,ep);
	else if(K > arr[x] && arr[x]+1 < arr[x])
		binary(sp,x);
}

int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%lld",&arr[i]);
	scanf("%lld",&K);
	binary(0,N-1);
	printf("NO\n");
}
