#include<stdio.h>
#include<string.h>
int c[20][20],d[20][20];
void run()
{
	int i,j,k,t,mark[20],min;
	for(i=0;i<20;i++)
	{
		for(j=i;j<20;j++)mark[j]=0;
		mark[i]=1;d[i][i]=0;
		do
		{
			min=100;
		for(j=0;j<20;j++)
			if(mark[j])
			{
				for(k=i+1;k<20;k++)
					if(!mark[k]&&c[k][j]&&c[k][j]+d[j][i]<min)
					{
						min=c[k][j]+d[j][i];
						t=k;
					}
			}
			if(min!=100)
			{
			mark[t]=1;
			d[i][t]=min;
			d[t][i]=min;
			}
		}while(min!=100);
	}
}
void main()
{
	int n,i,j,k,t;
	int count=0;
	while(scanf("%d",&n)==1)
	{
		memset(c,0,sizeof(c));
		for(i=0;i<19;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&k);
				c[i][k-1]=c[k-1][i]=1;
			}
			if(i!=18)scanf("%d",&n);
		}
		run();
		scanf("%d",&t);
		for(i=0;i<t;i++)
		{
			scanf("%d%d",&j,&k);
			if(!i)
				printf("Test Set #%d\n",++count);
			printf("%d to %d: %d\n",j,k,d[j-1][k-1]);
		}
		putchar('\n');
	}
}