
#include<stdio.h>
#include<string.h>

char input[1000000];
int max = 0,si=0;
void search_string( int s,int p)
{
	for (int i = p-1;i >= s; i--)
	{
		if(input[p] == input[i])
		{
			if(max < p-s)
			{
				max=p-s;
				si = s;
			}
			return;
		}
	}
	search_string(s,p+1);
}
int main()
{
	scanf("%[^\n]%*c",input);
	for (int i = 0; i < strlen(input); ++i)
		search_string(i,i+1);
	printf("%d\n",max);
	for (int i = si; i < si+max	; ++i)
		printf("%c",input[i]);
	printf("\n");	
}
