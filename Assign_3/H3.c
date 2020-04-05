#include<stdio.h>
int N,Q;
void BtoG(int r)
{
	int i=1,count = 1;
	while(r > i){
		count++;
		i<<=1;
	}
	i>>=1;
	int m =count;
	int x = 1,s = i,a;
	while(--count!=0)
	{
		if(r >= i){
			r-=i;
			a = x^1;
			x = 1;
			s+=a*i;
		}
		else{
			a = x^0;
			x = 0;
			s+=a*i;
		}
		i>>=1;
	}
	int j = 1;
	j<<=m-2;
	while(--m != 0){
		if(s>=j)
		{
			printf("%d",1 );
			s-=j;
		}
		else
			printf("%d",0);
		j>>=1;
	}
	printf("\n");
}
int GtoB(int r)
{
	int i=1,count = 1;
	while(r > i){
		count++;
		i<<=1;
	}
	i>>=1;
	r-=i;
	int x = 1,s =i;
	while(count--!=0)
	{
		i>>=1;
		if(r>=i){
			x^=1;
			r-=i;
		}
		else
			x^=0;
		s += x*i;
	}
	return s;
}
int main()
{
	char c;
	scanf("%d",&Q);
	for (int i = 0; i < Q; ++i)
	{
		scanf(" %c",&c);
		if(c == 'G'){
			scanf("%d",&N);
			if(N ==0)
				printf("%d\n", 0);
			else
				BtoG(N);
		}
		else if(c == 'D')
		{
			int a = 0;
			char s;
			while ((s = getchar()) != '\n') {
		  		a <<= 1;                     
		  		a += (s - '0') & 1;          
			}
			printf("%d\n",GtoB(a));
		}
	}
}
