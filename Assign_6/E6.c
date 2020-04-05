#include<stdio.h>
#include<string.h>
int top=-1,m,n,l;
char str[100000];
int stackx[100000];
int stacky[100000];
char mat[500][500];
int vis[500][500];
void pop()
{	
	if(top!=-1)
		top--;
}
void push(int x,int y)
{
	stackx[top+1]=x;
	stacky[top+1]=y;
	top++;
}
int inRange(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m)
		return 0;
	return 1;
}
int check(int x,int y)
{
	top=-1;
	int i,j,k=1;
	push(x,y);
	while(top!=-1)
	{
		if(k==l)
			return 1;
		x=stackx[top];
		y=stacky[top];
		vis[x][y]=1;
		//printf("top=%d x=%d y=%d strk[k]=%c\n",top,x,y,str[k]);
		if(inRange(x+1,y) && mat[x+1][y]==str[k] && !vis[x+1][y])
		{
			push(x+1,y);
			k++; continue;
		}
		if(inRange(x-1,y) && mat[x-1][y]==str[k] && !vis[x-1][y])
		{
			push(x-1,y);
			k++; continue;
		}
		if(inRange(x,y+1) && mat[x][y+1]==str[k] && !vis[x][y+1])
		{
			push(x,y+1);
			k++; continue;
		}
		if(inRange(x,y-1) && mat[x][y-1]==str[k] && !vis[x][y-1])
		{
			push(x,y-1);
			k++; continue;
		}
		pop();
		k--;
		vis[x][y]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			vis[i][j]=0;
	return 0;
}
int main()
{
	int i,j,t,flag=0;
	char ch;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf(" %c",&mat[i][j]);
		}
		scanf("%c",&ch);
	}
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%s",str);
		l=strlen(str);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				//printf("i=%d j=%d mat[i][j]=%c str[0]=%c\n",i,j,mat[i][j],str[0]);
				if(mat[i][j]==str[0])
				{
					if(check(i,j)){
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("%d %d\n",i,j);
		else
			printf("-1\n");
	}
}

