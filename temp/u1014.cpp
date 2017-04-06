#include<stdio.h>
#define N 100
void main()
{
	int i,j,n,num[N];
	while(scanf("%d",&n)==1)
	{
		j=0;
		for(i=9;i>=2;i--)
			while(n%i==0&&n>1)
			{
				num[j++]=i;
				n/=i;
			}
		if(n==1)
		{
		for(i=j-1;i>=0;i--)
			printf("%d",num[i]);
		printf("\n");
		}
		else printf("?\n");
	}
}