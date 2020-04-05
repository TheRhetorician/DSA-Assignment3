#include<stdio.h>
int arr[10];
void give(){
	long long int j = 1,s =0;
		for (int i = 1; i < 9 ; ++i)
		{
			while(arr[i]-- != 0)
			{
				s+=i*j;
				j*=10;
			}
		}
		while(arr[0]-- != 0)
			s*=10;
		printf("%lld\n",s);
}
int main()
{
	int Q,w,sum = 0;
	scanf("%d",&Q);
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d",&w);
		arr[w]++;
		sum+=w;
	}
	if(arr[0]==0)
	{
		printf("NO NUMBER\n");
		return 0;
	}
	else
	{
		if(sum%3==0)
		  give();
		else if(sum%3==1)
		{
			for (int i = 1; i < 10; i+=3)
			{
				if(arr[i]!=0)
				{
					arr[i]--;
					give();
					return 0;				
				}
			}
			for (int i = 2; i < 10; i+=3)
			{
				while(arr[i]-- !=0)
				{
					sum-=i;
					if(sum%3==0)
					{
						give();
						return 0;
					}
				}
			}
			printf("NO NUMBER\n");
		}
		else if(sum%3==2)
		{
			for (int i = 2; i < 10; i+=3)
			{
				if(arr[i]!=0)
				{
					arr[i]--;
					give();
					return 0;				
				}
			}
			for (int i = 1; i < 10; i+=3)
			{
				while(arr[i]-- !=0)
				{
					sum-=i;
					if(sum%3==0)
					{
						give();
						return 0;
					}
				}
			}
			printf("NO NUMBER\n");
		}
	}
}
