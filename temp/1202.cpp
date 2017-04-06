#include<stdio.h>
int c[150][20],n,a[50],b[50],num[50];
void init()
{
	int i,j;
	for(i=0;i<=144;i++)
		c[i][0]=c[i][i]=1;
	for(i=2;i<=144;i++)
		for(j=1;j<=12&&j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
}
void run()
{
	int i,j,count=0,sum,tot=0;
	for(i=0;i<n;i++)
	{
		tot+=a[i];
		for(j=0;j<count;j++)
			if(a[i]==b[j])
			{
				num[j]++;
				break;
			}
		if(j==count)
		{
			b[count]=a[i];
			num[count++]=1;
		}
	}
	sum=1;
	for(i=0;i<count;i++)
		for(j=0;j<num[i];j++)
		{
			sum*=c[tot][b[i]];
			sum/=j+1;
			tot-=b[i];
		}
	printf("%d\n",sum);
}
void main()
{
	int i;
	init();
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		run();
	}
}