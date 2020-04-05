#include<stdio.h>
#include<string.h>
int K,N,arr[16]={0},check[1000000]={0};
void print();
int give_dec(int arr[]);
void perm(int arr[])
{
	for (int i = 0; i < N; ++i)
	{
		if((arr[i]&1)==0)
		{
			arr[i]=1;
			check[give_dec(arr)]=1;
			perm(arr);
			arr[i]=0;
		}
	}
}
int give_dec(int arr[])
{
	int j = 1,s=0;
	for (int i = 0; i < N; ++i)
	{
		s+=arr[i]*j;
		j<<=1;
	}
	return s;
}
void find_binary(int n)
{
	int r=0,j=0;
	while(n > 0)
	{
		arr[j++]= n&1;
		n>>=1;
	}
}
void print()
{
	for (int i = N-1; i>=0; --i)
		printf("%d",arr[i]);
	printf("\n");
}
int main()
{
	scanf("%d %d",&N,&K);
	find_binary(K);
	print();
	perm(arr);
	int L = 1<<N;
	for (int i = 0; i < L; ++i)
	{
		if(check[i])
		{
			find_binary(i);
			print();
		}
	}
}
