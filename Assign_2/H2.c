#include<stdio.h>
int N,parent[501],store[501],l,level[501]={0},count=0;
void bfs()
{
	int front=0,back=0;
	store[back++]=0;
	while(front != back)
	{
		for (int i = 1; i < N ; ++i)
		{
			if(parent[i]==store[front])
			{
				level[i]=level[store[front]]+1;
				if(level[i]==l)
					count++;
				store[back++]=i;
			}
		}
		front++;
	}
}
int main()
{
	scanf("%d",&N);
	for (int i = 1; i < N; ++i)
		scanf("%d",&parent[i]);
	scanf("%d",&l);
	bfs();
	if (count == 0)
	{
		printf("%d\n",-1 );
		return 0;
	}
	printf("%d\n",count );
	for (int i = 0; i < N; ++i)
		if (level[i]==l)
			printf("%d ",i );
	printf("\n");
}