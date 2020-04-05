#include<stdio.h>
#include<string.h>
char arr[1000][50];
int N;
void swap(char* str1,char* str2)
{
	char a[50];
	strcpy(a,str1);
	strcpy(str1,str2);
	strcpy(str2,a);
}
int string_chk(char* str1,char* str2)
{
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	if(str1[0]!='-' && str2[0]!='-'){
	if(n1 > n2)
		return 0;
	else if(n2 > n1)
		return 1;
	for (int i=0; i<n1; i++) 
    { 
       if (str1[i] < str2[i]) 
          return 1; 
       if (str1[i] > str2[i]) 
          return 0; 
    } 
    return 0; 
	}
	if(str1[0]!='-' && str2[0]=='-'){
		return 0;
    } 
    if(str1[0]=='-' && str2[0]!='-'){
		return 1;
    } 
	if(str1[0]=='-' && str2[0]=='-'){
	if(n1 < n2)
		return 0;
	else if(n2 < n1)
		return 1;
	for (int i=0; i<n1; i++) 
    { 
       if (str1[i] > str2[i]) 
          return 1; 
       if (str1[i] < str2[i]) 
          return 0; 
    } 
    return 0; 
	}
}
void main()
{
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%s",arr[i]);
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			if(string_chk(arr[i],arr[j])){
				swap(arr[i],arr[j]);
			}
	for (int i = 0; i < N; ++i)
		printf("%s\n",arr[i]);
}
