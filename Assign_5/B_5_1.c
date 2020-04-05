#include<stdio.h>
long long int N,a[300000],sum=0;
void count(int x)
{
	while(x>0)
	{
		if(x&1)
			sum+=1;
		x>>=1;
	}
}
int main()
{
	scanf("%lld",&N);	
	for (int i = 0; i < N; ++i)
		scanf("%lld",&a[i]);
	for (int i = 0; i < N-1; ++i)
		for (int j = i+1; j < N; ++j)
			count(a[i]^a[j]);
	sum*=2;
	printf("%lld\n",sum%(1000000007) );
}
