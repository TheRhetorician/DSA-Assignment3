#include<stdio.h>
#include<string.h>
char input[1000000],store[1000000];
int max =0 ,length;
int check_pal(int start,int end)
{
	while(end > start)
		if(input[start++]!=input[end--])
			return 0;
	return 1;
}
void store_el(int start,int end)
{
	for (int i = start,j=0; i <= end,j<=end - start; ++i,++j)
		store[j]=input[i];
}
void store_pal(int x)
{
	for (int i = length-1; i>=x ; --i){
		if(i-x>=max && check_pal(x,i)){
			max = i-x;
			store_el(x,i);
		}
	}
}
int main()
{
	scanf("%s",input);
	length = strlen(input);
	for (int i = 0; i < length; ++i)
		store_pal(i);
	length = strlen(store);
	printf("%d\n",length );
	for (int i = 0; i < length; ++i)
		printf("%c",store[i]);
	printf("\n");
}