#include<stdio.h>
int g[200][200],d[200][200],mark[200];
int n;
void run()
{
	int i,j,k,tk,min,max,best,btime,count;
	btime=2100000000;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mark[j]=0;
			for(k=1;k<=n;k++)
				d[j][k]=g[j][k];
		}
		max=0;
		mark[i]=1;count=1;
		do
		{
		min=2100000000;
		for(j=1;j<=n;j++)
			if(mark[j])	
				for(k=1;k<=n;k++)
				if(!mark[k])
				{
				if(d[i][j]+d[j][k]<d[i][k])
					d[i][k]=d[i][j]+d[j][k];
					if(d[i][k]<min)
					{
						min=d[i][k];
						tk=k;
					}
				}
			if(min!=2100000000)
			{mark[tk]=1;count++;
			if(d[i][tk]>max)max=d[i][tk];
			}
		}while(min!=2100000000);
		if(count==n&&max<btime)
		{
			btime=max;
			best=i;
		}
	}
	if(btime!=2100000000)
	printf("%d %d\n",best,btime);
	else printf("disjoint\n");
}
void main()
{
	int i,j,t,k,time;
	scanf("%d",&n);
	while(n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(i==j)g[i][j]=0;
				else 
				g[i][j]=2100000000;
			}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for(j=0;j<t;j++)
			{
				scanf("%d%d",&k,&time);
				g[i][k]=time;
			}
		}
		run();
		scanf("%d",&n);
	}
}