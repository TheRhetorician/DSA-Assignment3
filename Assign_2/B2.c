#include<stdio.h>
int a,b,c,d,e,f,max;
int find(int x, int count);
int A(int x, int count)
{
	if((x-b)%a == 0 && x-b >= 0 && find((x-b)/a,++count))
			return 1;
		return 0;
}
int B(int x, int count)
{
	 if((x-d)%c == 0 && x-d>=0 && find((x-d)/c,++count))
			return 1;
	return 0;
}
int C(int x, int count)
{
	if((x-f)%e == 0 && x-f >=0 && find((x-f)/e,++count))
			return 1;
	return 0;
}
int find(int x , int count)
{
	if(x==0){
		if(max > count)
			max = count;
		return 1;
	}
	else if(A(x,count) || B(x,count) || C(x,count))
		return 1;
	else
		return 0;
}
int main()
{
	int n,x;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		max = x;
		if(find(x,0))
			printf("%d\n",max);
		else
			printf("%d\n",-1 );
	}
}