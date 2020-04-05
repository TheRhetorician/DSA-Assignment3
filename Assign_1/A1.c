
#include<stdio.h>
long long int n,m,x,y,P[100][100],Q[100][100];

int comp(int r, int s)
{
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			if(P[r+i][s+j] != Q[i][j])
				return 0;
	return 1;
}

int main()
{
	int r,c;
	scanf("%lld%lld",&n,&m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%lld",&P[i][j]);

	scanf("%lld%lld",&x,&y);
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			scanf("%lld",&Q[i][j]);	
	 r = n - (x-1);
	 c = m - (y-1);

	 for (int i = 0; i < r; ++i){
	 	for (int j = 0; j < c; ++j)
	 	{
	 		int a = comp(i,j);
	 		if(a){
	 			printf("YES\n%d %d\n",i,j);
	 			return 0;
	 		}

	 	}
	 }
	 printf("NO\n");
}
