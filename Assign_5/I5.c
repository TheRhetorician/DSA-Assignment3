#include<stdio.h>
#include<stdlib.h>
int N;
long long int arr[200000],K,diff=1000000,u=0,v=0;
int main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%lld",&arr[i]);
	scanf("%lld",&K);
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			if(arr[i]+arr[j]==K && diff > abs(u-v))
			{
				u = arr[i];
				v = arr[j];
				diff = abs(u-v);
			}
		}
	}
	printf("YES\n");
	printf("%lld %lld\n",u,v );
}
