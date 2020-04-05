#include<stdio.h>
#include<string.h>
int N,M,X,arr[1000][1000]={0},vis[1000]={0},track[1000],min,node=-1;
void prim(int s)
{
	vis[s]=1;
	for (int i = 0; i < N; ++i)
		if(arr[s][i] && !vis[i])
			prim(i);
}
void rem(int j)
{
	int count =0,c = 0;
	for (int i = 0; i < N; ++i){
		if(arr[i][j]){
			arr[i][j]=arr[j][i]=0;
			track[count++]=i;
		}
	}
	prim(X);
	for (int i = 0; i < N; ++i)
	{
		if(vis[i])
		{
			c++;
			vis[i]=0;
		}
	}
	if(c < min)
	{
		min = c;
		node = j;
	}
	for (int i = 0; i < count; ++i)
		arr[j][track[i]] = arr[track[i]][j]=1;
}
int main()
{
	int u,v;
	scanf("%d%d",&N,&M);
	min = N-1;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&u,&v);
		arr[u][v]=arr[v][u]=1;
	}
	scanf("%d",&X);
	for (int i = 0; i < N; ++i)
		if(arr[X][i])
			rem(i);
	if(node == -1)
		printf("BLACKOUT\n");
	else
		printf("%d\n",node );
}
