#include<stdio.h>
#include<string.h>
int M ,N, travel[501]={0},parent[501][501]={0},flag = 0;
void check_travel(int x)
{
	for (int i = 1; i <= N ; ++i)
	{
		if(parent[x][i] && !travel[i]){
				travel[i]=1;
				check_travel(i);
		}
	}
	return;
}
void check()
{
	int count =0;
	for (int i = 1; i <= N; ++i)
		if(travel[i])
			count++;
	if(count == N)
		flag=1;
	return;
}
int main()
{
	int x,y;
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&x,&y);
		parent[x][y]=1;	
	}
	for (int i = 1; i <= N ; ++i)
	{
		travel[i]=1;
		check_travel(i);
		check();
		if(flag){
			printf("%d\n",i );
			return 0 ;
		}
		memset(travel , 0 ,sizeof(travel));
	}
	printf("BAD LUCK \n");
}