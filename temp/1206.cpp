#include<stdio.h>
#include<string.h>
int point[1000],maxp[10001][10][10],pre[10001][10][10];
int n,m;
void run()
{
	int i,j,ti,tj,max,k,h;
	if(n==1)
	{
		printf("0\n");
		return;
	}
	if(n==2)
	{
		printf("00\n");
		return;
	}
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			maxp[3][i][j]=-2100000000;
			for(k=0;k<10;k++)
				if(point[i*100+j*10+k]>maxp[3][i][j])
				{
			maxp[3][i][j]=point[i*100+j*10+k];
			pre[3][i][j]=k;
				}
		}
	for(i=4;i<=n;i++)
		
		for(j=0;j<10;j++)
			for(k=0;k<10;k++)
			{
				maxp[i][j][k]=-2100000000;
				for(h=0;h<10;h++)
		if(point[j*100+k*10+h]+maxp[i-1][k][h]>maxp[i][j][k])
		{
			maxp[i][j][k]=point[100*j+k*10+h]+maxp[i-1][k][h];
			pre[i][j][k]=h;
		}
			}
	max=-2100000000;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(maxp[n][i][j]>max)
			{
				max=maxp[n][i][j];
				ti=i;tj=j;
			}
	printf("%d",ti);
	do
	{
		printf("%d",tj);
		i=ti;
		ti=tj;
		tj=pre[n--][i][tj];
	}while(n>2);
	printf("%d\n",tj);
}
void main()
{
	int i,j,k;
	while(scanf("%d%d",&m,&n)==2)
	{
		memset(point,0,sizeof(point));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j,&k);
			point[j]=k;
		}
		run();
	}
}