#include<stdio.h>
#define N 1010
int f[N][N],cla[N],h[N],g[N][N],d[600];
int c,l,n,t[N],count;
int di(int tot)
{
	if(tot==l)return 0;
	if(l-tot>=1&&l-tot<=10)return -c;
	return (l-tot-10)*(l-tot-10);
}
void init()
{
	int i,j,tot;
	for(i=0;i<=l;i++)
		d[i]=di(i);
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			g[i][j]=2100000000;
	for(i=0;i<=n;i++)
		g[0][i]=d[0];
	for(i=1;i<=n;i++)
	{
		tot=0;
		for(j=0;i+j<=n+1;j++)
		{
			if(tot<=l)g[i][j]=d[tot];
			tot+=t[i+j];
			if(tot>l)break;
		}
		h[i]=j;
	}
	j=1;i=1;cla[0]=0;
	do
	{
		cla[i]=cla[i-1]+h[j];
		j=cla[i]+1;
		i++;
	}while(j<=n);
	count=i;
}
void run()
{
	int i,j,k;
	init();
	for(i=0;i<=count;i++)
		for(j=0;j<=n;j++)
			f[i][j]=2100000000;
	for(i=0;i<=cla[1];i++)
		f[1][i]=g[1][i];
	if(i>n)
	{
		printf("Minimum number of lectures: %d\n",1);
		printf("Total dissatisfaction index: %d\n",g[1][n]);
		return;
	}
	for(i=2;;i++)
	{
		for(j=0;j<=cla[i];j++)
			for(k=0;k<=j;k++)
			{
				if(g[j-k+1][k]==2100000000)break;
				if(f[i-1][j-k]+g[j-k+1][k]<f[i][j])
					f[i][j]=f[i-1][j-k]+g[j-k+1][k];
			}
		if(j>n)
		{
		printf("Minimum number of lectures: %d\n",i);
		printf("Total dissatisfaction index: %d\n",f[i][n]);
		return;
		}
	}
}
void main()
{
	int cas,now,i,tot;
	scanf("%d",&cas);
	for(now=0;now<cas;now++)
	{
		if(now)putchar('\n');
		tot=0;
		scanf("%d",&n);
		while(n)
		{
			if(tot)printf("\n");
			scanf("%d%d",&l,&c);
			for(i=1;i<=n;i++)
				scanf("%d",&t[i]);
			t[0]=0;
			printf("Case %d:\n\n",++tot);
			run();
			scanf("%d",&n);
		}
	}
}