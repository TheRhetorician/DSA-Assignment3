#include<stdio.h>
#include<stdlib.h>
int N,M,arr[500][500],spx,spy,epx,epy,r,s;
void map(int a, int b)
{
	if(a == epx && b == epy)
	{
		printf("YES\n");
		exit(0);
	}
	if(!arr[a+r][b] && !arr[a][b+s])
		return;
	if(arr[a+r][b] && a != epx)
		map(a+r,b);
	else if(arr[a][b+s] && b != epy)
		map(a,b+s);
}
int main()
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d",&arr[i][j]);
	scanf("%d%d%d%d",&spx,&spy,&epx,&epy);
	(spx > epx)?r = -1:1;
	(spy > epy)?s = -1:1;
	if(arr[spx][spy] && arr[epx][epy])
		map(spx,spy);
	printf("NO\n");
}
