#include<stdio.h>
int N,arr[100000]={0},check[100000]={0},dum[100000]={0},vis[100000]={0},leaf=0,min,M=0;
void dfs(int x,int count)
{
	vis[x]=1;
	for (int i = 0; i < N; ++i)
		if (arr[i]==x && !vis[i])
			dfs(i,count+1);
	if(count < min && !check[x]){
		min = count;
		M = 1;
		leaf = x;
	}
	else if(count == min && !check[x])
	{
		M++;
		if(leaf > x)
			leaf = x;
	}
	vis[x]=0;
}
int main()
{
	int u,v,count =0;
	scanf("%d",&N);
	min = N;
	arr[0]=0;
	for (int i = 1; i < N; ++i)
		arr[i]=-1;
	for (int i = 0; i < N-1; ++i)
	{
		scanf("%d%d",&u,&v);
		if(arr[u]!=-1){
			arr[v]=u;
			check[u]=1;
		}
		else if(arr[v]!=-1){
			arr[u]=v;
			check[v]=1;
		}
		else
		{
			dum[count++]=u;
			dum[count++]=v;
		}
	}
	for (int i = 0; dum[i]!=0; i+=2)
	{
		if(arr[dum[i]]!=-1){
			check[dum[i]]=1;
			arr[dum[i+1]]=dum[i];
		}
		else{
			check[dum[i+1]]=1;
			arr[dum[i]]=dum[i+1];
		}
	}
	dfs(0,0);
	printf("%d\n",M);
	printf("%d\n",leaf);
}
