#include<stdio.h>
#include<math.h>

int main()
{
	int n,x;
	scanf("%d",&n);
	int bin[n][32];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(int j=31;j>=0;j--)
		{
			bin[i][j]=x%2;
			x/=2;
		}
	}
	int sum=0;
	for(int i=31;i>=0;i--)
	{
		int one=0;
		for(int j=0;j<n;j++)
		{
			if(bin[j][i]==1)
				one++;		
		}
		sum+=one*(n-one)*2;
	}
	printf("%d\n",sum%(7+(int)pow(10,9)));
}
