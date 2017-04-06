#include<stdio.h>
#define N 1000
int a[N][35];
void main()
{
	int i,j,n,k,m,t;
	while(scanf("%d",&k)==1)
	{
		n=k*(k-1)+1;
		m=1;
		for(i=1;i<=k;i++)
			for(j=1;j<=k;j++)
			{
				if(j==1)
					a[i][j]=1;
				else a[i][j]=++m;
			}
		for(m=1;m<k;m++)
			for(i=1,t=2;i<k;i++,t=i+1)
				for(j=1;j<=k;j++)
				{
				if(j==1)
				a[m*(k-1)+i+1][1]=m+1;
				else 
				{
				if(t<=1)t+=k-1;
				a[m*(k-1)+i+1][j]=a[j][t];
				t-=m-1;
				}
				}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}