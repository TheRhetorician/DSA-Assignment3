#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
double m[200000];
void slope(int arr[n][3],int i)
{
	double d;
	int j;
	//printf("inside slope");
	for(j=0;j<n;j++)
	{
		d = ((arr[j][2]-arr[i][2]))/((arr[j][1]-arr[i][1]));
		m[j]=d;
	}
	printf("end slope");
}
void sort(int arr[][3],int x)
{
	int i;
	double d;
	for(i=0;i<n-1;i++)
	{
		int j;
		double a = atan(m[i]);
		for(j=i+1;j<n;j++)
		{
			double b = atan(m[j]);
			if(a>b)
			{
				double t=m[i];
				m[i]=m[j];
				m[j]=t;
				int q = arr[i][0];
				arr[i][0]=arr[j][0];
				arr[j][0]=q;
				q = arr[i][1];
				arr[i][1]=arr[j][1];
				arr[j][1]=q;
				q = arr[i][2];
				arr[i][2]=arr[j][2];
				arr[j][2]=q;
			}
			if(a==b)
			{
				double d1 = (arr[i][1]-arr[x][1])*(arr[i][1]-arr[x][1]) + (arr[i][2]-arr[x][2])*(arr[i][2]-arr[x][2]);
				d1 = sqrt(d1);
				double d2 = ((arr[j][1]-arr[x][1])*(arr[j][1]-arr[x][1]))+ ((arr[j][2]-arr[x][2])*(arr[j][2]-arr[x][2]));
				d2 = sqrt(d2);
				if(d2<d1)
				{
					double t=m[i];
					m[i]=m[j];
					m[j]=t;
					int q = arr[i][0];
					arr[i][0]=arr[j][0];
					arr[j][0]=q;
					q = arr[i][1];
					arr[i][1]=arr[j][1];
					arr[j][1]=q;
					q = arr[i][2];
					arr[i][2]=arr[j][2];
					arr[j][2]=q;
				}
			}
			
		}
	}
}
int main()
{
	scanf("%d",&n);
	int arr[n][3];
	scanf("%d%d%d",&arr[0][0],&arr[0][1],&arr[0][2]);
	int min = arr[0][2];
	int ind=0;
	int i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		if(arr[i][2]<min)
		{
			ind = i;
			min = arr[i][2];
		}
	}
	slope(arr,i);
	sort(arr,i);
	for(i=0;i<n;i++)
	printf("%d ",arr[i][0]);
	return 0;
}

