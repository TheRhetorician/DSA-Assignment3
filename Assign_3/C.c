#include <stdio.h>
#include <stdlib.h>
void main()
{
  int x1,y1,z1;
  int x2,y2,z2;
  scanf("%d%d%d",&x1,&y1,&z1);//scan
  scanf("%d%d%d",&x2,&y2,&z2); 
  int n1,n2,n3,n;
  long long int ans=1,den=1;
  n1=abs(x1-x2);//find absolute values
  n2=abs(y1-y2);
  n3=abs(z1-z2);
  n=n1+n2+n3;
  int k= 998244353-2;
  while(n!=0)//find (n!)mod 998244353
  {
    ans=(ans*n)%998244353;
    n--;
  }
  while(n1!=0)//find (n1!) mod 998244353
  {
    den=(den*n1)%998244353;
    n1--;
  }
   while(n2!=0)//same
  {
    den=(den*n2)%998244353;
    n2--;
  }
   while(n3!=0)//same
  {
    den=(den*n3)%998244353;
    n3--;
  }
  while(k!=0)//find (n!/n1!*n2!*n3!)mod 998244353 using fermat's little theorem a^p-1=1mod p, p is prime
  {
    ans=(ans*den)%998244353;
    k--;
  }
  printf("%lld",ans);
}
