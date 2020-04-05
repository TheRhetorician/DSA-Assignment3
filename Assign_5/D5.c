#include<stdio.h>
#include<stdlib.h>
int N,sum=0;
long long int arr[100000],M,sub[100000]={0};
void check(int x)
{
	int s = sub[x],n=1;
	for (int i = x+1; i < N; ++i)
	{
		if(s+sub[i]>M)
			break;
		sum+=n;
		s+=sub[i];
		n+=1;
	}
}
int main()
{
	scanf("%d%lld",&N,&M);
	int j = 1;
	for (int i = 0; i < N; ++i){
		scanf("%lld",&arr[i]);
		if(i>=1)
			sub[i]=arr[i]-arr[i-1];
	}
	for (int i = 1; i < N; ++i)
		if(sub[i]<M)
			check(i);
	printf("%d\n",sum );
}
