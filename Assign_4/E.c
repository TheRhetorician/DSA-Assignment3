#include<stdio.h>
#include<stdlib.h>
long long int arr[200000],N,count=0;
int main()
{
	scanf("%lld",&N);
	for (int i = 0; i < N; ++i)
		scanf("%lld",&arr[i]);
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < j; ++i)
			if(arr[i]>arr[j])
				count++;
	printf("%lld\n",count );
}
