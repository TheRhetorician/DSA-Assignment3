#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N,M;
char mat[500][500],str[100];
int grid(int x,int y)
{
	int i = 1;
	while(str[i]!='\0')
	{
		if(str[i]== mat[x+1][y] && x+1 < N)
			++x;
		else if(str[i]==mat[x][y+1] && y+1 < M)
			y++;
		else if(str[i]==mat[x-1][y] && x-1>=0)
			--x;
		else if(str[i]==mat[x][y-1] && y-1>=0)
			--y;
		else 
			return 0;
		i++;
	}
	return 1;
}
void find()
{
	for (int i = 0; i < N-1; ++i)
	{
		for (int j = 0; j < M-1; ++j)
		{
			if(mat[i][j]==str[0] && grid(i,j))
			{
				printf("%d %d\n",i,j );
				return;
			}
		}
	}
	printf("%d\n",-1);
}
int main()
{
	scanf("%d%d",&N,&M);
	char c;
	scanf("%c",&c);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j)
			scanf("%c",&mat[i][j]);
		scanf("%c",&c);
	}
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%s",str);
		find();
	}
}
