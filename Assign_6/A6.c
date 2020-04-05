#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
 char string[3000000],ans[3000000];//make 2 strings one question ,one answer
 scanf("%s",string);
 int k=1;
 ans[0]=string[0];//copy 0th index
 for(int i=1;i<strlen(string);i++)
 {
   if(string[i]!=ans[k-1])//if ith index of given string not the same as already the one entered in ans string 
   {
     ans[k++]= string[i];//copy it and continue, k is always on the position where the char is to be entered
     continue;
   }
   while(string[i]==ans[k-1])//if same then increase i till that character is consecutive
   {
     i++;
   }
   k--;//remove the already entered char by reducing k, k signifies position where new char is to be entered
   i--;//reduce i by 1 because it is going to inc in loop
 }
 ans[k]='\0';
 if(strlen(ans)==0)
  return printf("VANISHED");
 return printf("%s",ans);
}
