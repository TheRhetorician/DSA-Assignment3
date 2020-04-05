#include<stdio.h>
int Q,N,sq;
void sqroot(int u,int l)
{
	if((u-l)/2==0 )
	{
		if(u*u == N)
			sq = u;
		else
			sq = l;
		return;
	}
	int mid = l + (u-l)/2;
	int r = N - mid*mid;
	if(r > 0)
		sqroot(u,mid);
	else
		sqroot(mid,l);
}
int main()
{
	scanf("%d",&Q);
	for (int i = 0; i < Q; ++i){
		scanf("%d",&N);
		sqroot(N,0);
		printf("%d\n",sq);
	}
}
