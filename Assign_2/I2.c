#include<stdio.h>
int barr[10],sarr[10];
int main()
{
	char c;
	long long int small = 0, big = 0,h=1;
	scanf("%c",&c);
	
	do
	{
		barr[c-'0']++;
		sarr[c-'0']++;
		scanf("%c",&c);
	}while(c != '\n');

	for (int i = 1; i <= 9 ; ++i)
	{
		while(barr[i]-- >0)
		{
			printf("%d ",barr[i]);
			big+=h*i;
			h*=10;
		}
	}
	printf("\n");

	while(barr[0]-- > 0){
		big*=10;
		h*=10;
	}
	h/=10;
	for (;sarr[1]-- > 0; h/=10)
		small += h;
	while(sarr[0]-- > 0)
		h/=10;
	for (int i = 2; i <= 9; ++i)
	{
		while(sarr[i]-- > 0)
		{
			small+=i*h;
			h/=10;
		}
	}
	printf("%lld\n",big - small );
}
