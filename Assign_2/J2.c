#include<stdio.h>
int prime(int n);
int main()
{
	long long int N,i=2,x=0,count;
	scanf("%lld",&N);
	while(i*i <= N)
	{
		count = 0;
		while(N%i==0){
			if(prime(i)==1)
			{
			count += 1;
			if(count == 1)
				x^=i;
				printf("%lld\n",x);
			N=(N/i);
			}
		}
		i+=1;
	}
	x^=N;
	printf("%lld\n", x);
}
int prime(int n)
{
	int i,c=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		c++;
	}
	return c;
}
