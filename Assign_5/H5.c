#include<stdio.h>
#include<stdlib.h>
int N,M,Z,arr[10000][10000]={0};
int main()
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
				scanf("%d",&arr[i][j]);
	scanf("%d",&Z);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(arr[i][j]==Z)
			{
				printf("YES\n");
				printf("%d %d\n",i,j );
				exit(0);
			}
		}
	}
	printf("MISSING\n");
}
