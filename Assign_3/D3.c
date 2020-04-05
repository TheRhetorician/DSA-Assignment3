#include<stdio.h>
#include<string.h>
char S[1000],W[1000],c=0,lenW,lenS;
void check_str(int r)
{
	int count=0;
	for (int i = r,j =0;j < lenW ; ++i,++j)
	{
		if(S[i]!=W[j])
			count++;
		if(count>1)
			return;
	}
	c++;
}
int main()
{
	scanf("%s",S);
	scanf("%s",W);
	lenW = strlen(W);
	lenS = strlen(S);
	for (int i = 0; i <= lenS-lenW; ++i)
		check_str(i);
	printf("%d\n",c );
}
