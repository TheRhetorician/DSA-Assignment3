#include<stdio.h>
#include<string.h>
int palin(char ch[]);
void main()
{
	char ch[1000000];
	char pal[1000000];
	char qw[1000000];
	scanf("%[^\n]*c",ch);
	int l = sizeof(ch)/sizeof(ch[0]);
	int i;
	int j=0;
	for(i=0;i<l;i++)
	{
		char ch1 = ch[i];
		
		if(ch1!=' ')
		{
			pal[i]=ch1;
		}
		else
		{
			printf("%s ",pal);
			int t = palin(pal);
			if(t==1)
			{
				int k;
				int r = sizeof(pal)/sizeof(pal[0]);
				for(k=0;k<r;k++)
				{
					qw[j]=pal[k];
					j++;
				}
				qw[j]=' ';
				j++;
			}	
		}
	}
	l = sizeof(qw)/sizeof(qw[0]);
	for(i=0;i<l;i++)
	{
		if(qw[i]==' ')
		printf("\n");
		else
		printf("%c",qw[i]);
	}
}
int palin(char ch[])
{
	int c=1,i;
	int l = sizeof(ch)/sizeof(ch[0]);
	for(i=0;i<l/2;i++)
	{
		if(ch[i]!=ch[l-i-1])
		c=0;
	}
	return c;
}
