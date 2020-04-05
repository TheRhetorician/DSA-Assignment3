#include<stdio.h>
int adj[500][500];
int vis[500];
int distance[500];
int isNode[500];
int n,k,top;
int stack[500];
void push(int ele)
{
	stack[++top]=ele;
}
void pop()
{
	if(top!=-1)
		top--;
}
void dfs(int x)
{
	push(x);
	while(top!=-1)
	{
		x=stack[top];
		vis[x]=1;
		pop();
		for(int i=0;i<n;i++)
		{
			if(adj[x][i]!=-1 && !vis[i])
			{
				push(i);
				distance[i]=distance[x]+adj[x][i];
			}
		}
	}
}
int main()
{
	int i,j,k,x,y,z,count=0;
	for(i=0;i<500;i++)
		for(j=0;j<500;j++)
			adj[i][j]=-1;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		adj[x][y]=z;
		adj[y][x]=z;
	}
	for(i=0;i<n;i++){
		count=0;
		for(j=0;j<n;j++){
			if(adj[i][j]!=-1)
				count++;
		}
		if(count==1)
			isNode[i]=1;
	}
	scanf("%d %d",&i,&k);
	dfs(i);
	for(i=0;i<n;i++)
		if(isNode[i] && distance[i]<=k)
			printf("%d ",i);
	printf("\n");
}
