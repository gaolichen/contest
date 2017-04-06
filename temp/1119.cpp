#include<stdio.h>
#include<string.h>
#define N 1100
int low[N],d[N],mark[N],son,dfn,n;
char g[N][N],tral[N];
int min(int i,int j)
{
	if(i>j)return j;
	return i;
}
void run(int v)
{
	int u;
	for(u=1;u<=n;u++)
		if(g[u][v])
		{
			if(!tral[u])
			{
				tral[u]=1;
				dfn++;d[u]=low[u]=dfn;
				run(u);
				low[v]=min(low[v],low[u]);
				if(low[u]>=d[v])
				{
					if(v!=1)
						mark[v]++;
					if(v==1)son++;

				}
			}
			else low[v]=min(low[v],d[u]);
		}
}
void init()
{
	int i;
	low[1]=d[1]=1;
	dfn=1;son=0;
	for(i=0;i<=n;i++)
		tral[i]=0;
	tral[1]=1;
	for(i=0;i<=n;i++)
		mark[i]=0;
}
void main()
{
	int i,j,count=0,find;
	scanf("%d",&i);
	while(i)
	{		
		memset(g,0,sizeof(g));
		n=-1;
		while(i)
		{
			if(i>n)n=i;
		scanf("%d",&j);
		if(j>n)n=j;
		g[i][j]=g[j][i]=1;
		scanf("%d",&i);
		}
		if(count)putchar('\n');
		printf("Network #%d\n",++count);
		init();
		run(1);
		mark[1]=son-1;
		find=0;
		for(i=1;i<=n;i++)
			if(mark[i])
			{
			find=1;
		printf("  SPF node %d leaves %d subnets\n",i,mark[i]+1);
			}
		if(!find)
			printf("  No SPF nodes\n");
		scanf("%d",&i);
	}
}