#include<stdio.h>
int n,m,k=0,flag;
int adj[1000][1000];
int stack[1000]={0};
int vis[1000]={0};
int cycle[1000]={0};
void dfs(int x)
{
	vis[x]=1;
	cycle[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(adj[x][i] && cycle[i])
			flag=-1;
		if(adj[x][i] && !vis[i])
			dfs(i);
	}
	cycle[x]=0;
	stack[k++]=x;
}
int main()
{
	int i,j,x,y,root;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		if(y!=-1)
			adj[y][x]=1;
	}
	for(i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
		for(j=1;j<=n;j++)
			cycle[j]=0;
	}
	if(flag==-1){
		printf("NOT POSSIBLE\n");
		return 0;
	}
	for(i=k-1;i>=0;i--)
		printf("%d ",stack[i]);
	printf("\n");	
}
