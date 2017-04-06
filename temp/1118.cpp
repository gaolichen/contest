#include<stdio.h>
#include<string.h>
#define N 1000
int a[N][10],f[N][N],mark[N],h[N],n,g[N];
int tot,count;
void init()
{
	int i,j,k;
	tot=0;
	for(i=0;i<count;i++)
	{
		for(j=0;j<tot;j++)
		{
			for(k=0;k<n;k++)
				if(a[i][k]!=a[g[j]][k])
					break;
			if(k==n)break;
		}
		if(j==tot)
		{
			h[i]=tot;
			g[tot++]=i;
		}
		else h[i]=j;
	}
	for(i=0;i<tot;i++)
		for(j=0;j<tot;j++)
			f[i][j]=0;
	for(i=2;i<count-1;i+=2)
		f[h[i]][h[i+1]]=1;
}
void run()
{
	int i,j,open,close,sk[N],find=0;
	init();
	memset(mark,0,sizeof(int)*tot);
	open=close=0;
	sk[0]=h[0];mark[h[0]]=1;
	if(h[0]==h[1])find=1;
	while(open<=close&&!find)
	{
		i=sk[open];
		for(j=0;j<count;j++)
			if(!mark[h[j]]&&f[i][h[j]])
			{
				sk[++close]=h[j];
				mark[h[j]]=1;
				if(h[j]==h[1])find=1;
			}
		open++;
	}
	if(find)
		printf("can be travelled\n");
	else printf("cannot be travelled\n");
}
void main()
{
	int i,j,num=0;
	scanf("%d",&n);
	while(n)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[0][j]);
		for(j=0;j<n;j++)
			scanf("%d",&a[1][j]);
		i=2;
		scanf("%d",&a[i][0]);
		while(a[i][0]!=-1)
		{
			for(j=1;j<n;j++)
				scanf("%d",&a[i][j]);
			i++;
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			scanf("%d",&a[++i][0]);
		}
		count=i;
		printf("Maze #%d ",++num);
		run();
		scanf("%d",&n);
	}
}