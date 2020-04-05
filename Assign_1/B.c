#include<stdio.h>
int prime(int i);
void main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int arr[10];
	int i;
	for(i=0;i<10;i++)
	arr[i]=0;
	for(i=a;i<=b;i++)
	{
		int t = prime(i);
		if(t==1)
		{
			t=i;
			while(t>0)
			{
				int p = t%10;
				arr[p]++;
				t=t/10;
			}
		}
	}
	int max = arr[0];
	int x=0;
	for(i=0;i<10;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			x=i;
		}
	}
	printf("%d %d",x,max);
}
int prime(int i)
{
	int c=0,j;
	for(j=1;j<=i;j++)
	{
		if(i%j==0)
		c++;
	}
	if(c==2)
	j=1;
	else if(c>2)
	j=0;
	return j;
}
