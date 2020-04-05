#include<stdio.h>
int N,arr[100000],diff[100000],done[100000],count=0,max=0;
int Not_in_done(int x)
{
	for (int i = 0; i <= count; ++i){
		if(x == done[i]){
			++diff[i];
			return 0;
		}
	}
	++diff[count+1];
	return 1;
}
int main()
{	
	int max_el;
	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf("%d",&arr[i]);
		if(Not_in_done(arr[i]))
			done[++count] = arr[i];
	}
	for (int i = 1; i <= count; ++i){
		if(max < diff[i]){
			max = diff[i];
			max_el = done[i];
		}
		else if(max == diff[i]){
			if(max_el<done[i])
				max_el=done[i];
		}
	}
	if((max > N/2 && N%2 == 1)|| max>=N/2 && N%2 == 0)
		printf("%d\n",max_el );
	else
		printf("NO MAJORITY ELEMENT\n");
}
