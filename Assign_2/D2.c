#include<stdio.h>
#include<string.h>
int N,M,graph[501][501]={0},vis[501]={0},max=0,store[501]={0};
void store_arr();
void dfs(int node , int count)
{
	vis[node]=1;
	for (int i = 1; i <= N; ++i)
		if(graph[node][i])
			if(!vis[i])
				dfs(i,count+1);
	if(count > max){
		max = count;
		memset(store,0,sizeof(store));
		store_arr();
	}
	vis[node]=0;
}
void store_arr()
{
	for (int i = 1; i <= N; ++i)
		if(vis[i])
			store[i]=vis[i];
}
int main()
{
	int x,y;
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&x,&y);
		graph[x][y]=graph[y][x]=1;
	}
	for (int i = 1; i <= N; ++i)
		dfs(i,1);
	if(max==N)
		printf("%d\n",-1 );
	else
	{
		printf("%d\n",N-max);
		for (int i = 1; i <= N; ++i)
			if(!store[i])
				printf("%d ",i);
		printf("\n");
	}
}
