#include<stdio.h>
int N,mem[500001]={0},count = 1,max =0,max_el;
int comp(int x,int num)
{
	if(x >= count)
	{
		if(x%2)
			comp(3*x+1,num+1);
		else
			comp(x/2,num+1);
	}
	else if(x == 1 || x < count )
		return num+mem[x];
}
int main()
{
	scanf("%d",&N);
	mem[1]=1;
	for (int i = 2; i < N; ++i)
	{
		mem[++count]=comp(i,0);
		if(mem[count]>max){
			max = mem[count];
			max_el = count;
		}
	}
	printf("%d %d\n",max_el,max );
}
