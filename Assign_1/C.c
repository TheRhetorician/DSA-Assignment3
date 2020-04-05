
#include<stdio.h>
#include<string.h>
char input[1000000], word[1000000], test[1000000];
int chk[1000000];
char* ptr;
int check_for_let(char c)
{
	int i = 0;
	do{
		if(c == word[i] && !chk[i])
			return i;
	}while(++i != strlen(word));
	return -1;
}
int check(char* ptr, int count, int sp)
{
	char* p ;
	p = ptr;
	do{
		sp++;
		int i = check_for_let(*p);
		if(i>=0){
		 chk[i]++;
		 count++;
		}
		if(count == 0)
			return -1;
		else if(count == strlen(word))
			return sp;
	}while(*p++ != '\0');
	return 0;
}
int main()
{
	int c =0, sp=0,  ep=0;
	scanf("%[^\n]%*c",input);	
	scanf("%[^\n]%*c",word);
	char*p;
	p = input;
	int min = strlen(input);	
	do{
		int r = check(p+c,0,c);
		if(r > 0 && r-c < min)
			{
				sp = c;
				ep = r;
				min = r-c;
			}
		for (int i = 0; i < strlen(input); ++i)
			chk[i]=0;
	}while(++c != strlen(input));
	printf("%d %d\n",sp,ep-1 );
	for (int i = sp; i < ep; ++i)
		printf("%c",input[i]);
	printf("\n");
	return 0;
}
