#include<stdio.h>
#include<string.h>
int main()
{
	char ch[1000000];
	gets(ch);
	int t = strlen(ch);
	ch[t]=' ';
	char fn[1000000];
	int i;
	int x=0;
	char str[strlen(ch)];
	char s[strlen(ch)];
	for(i=0;i<strlen(ch);i++)
	{
		str[i]='\0';
		s[i]='\0';
	}
	for(i=0;i<strlen(ch);i++)
	{
		char ch1 = ch[i];
		if(ch1!=' ')
		{
			fn[x]=ch1;
			x++;
		}
		else
		{
			int j;
			for(j=x-1;j>=0;j--)
			{
				printf("%c",fn[j]);
				s[x-j-1]=fn[j];
			}
				if(strcmp(s,fn)==0)
				{
					strcat(str,fn);
					str[strlen(str)]=' ';
				}
			printf(" ");
			for(j=0;j<x;j++)
			fn[j]='\0';
			x=0;
		}
	}
	printf("\n");
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==' ')
		printf("\n");
		else
		printf("%c",str[i]);
	}
	return 0;
}
