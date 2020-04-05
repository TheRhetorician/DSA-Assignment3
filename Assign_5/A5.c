#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,U,V,v,arr[1500][1500]={0},count[1500]={0},vis[1500]={0},max = 0;
void dfs(int n,int count)
{
	vis[n]=1;
	for (int i = 0; i < N; ++i)
		if(arr[n][i] && !vis[i])
			dfs(i,count+1);
	else if(count >= max)
	{
		max = count;
		v = n;
	}
	vis[n]=0;
}
int main()
{
	scanf("%d",&N);
	int x,y;
	for (int i = 0; i < N-1; ++i)
	{
		scanf("%d%d",&x,&y);
		arr[x][y]=arr[y][x] = 1;//    COUNT ARRAY STORES NO. OF EDGES LINKED TO THE NODE
		count[x]++;
		count[y]++;
	}
	for (int i = 1; i < N; ++i){
		if(count[i]==1)//     LEAF NODE
		{
			int a = max;
			dfs(i,0);
			if(max > a){
				U=i;
				V=v;
			}
			if(max==a)
			{
				if(U>i)
				{
					U=i;
					V=v;
				}
				else if(U==i && V<v)
				{
					V=v;
				}
			}
		}
	}
	printf("%d\n",max );
	printf("%d %d\n",U,V );
}
