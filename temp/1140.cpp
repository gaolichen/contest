#include<stdio.h>
#include<string.h>
int map[200][400],ns[400],nc[200],ch[400],mark[200];
int n,p;
void run()
{
	int i,j,k,temp,min;
	if(n<p)
	{
		printf("NO\n");
		return;
	}
	memset(mark,0,sizeof(mark));
	memset(ch,0,sizeof(ch));
	for(j=0;j<p;j++)
	{
		min=-1;
		for(i=0;i<p;i++)
		if(!mark[i])
		{
			if(nc[i]<=0)
			{
				printf("NO\n");
				return;
			}
			if(min==-1||nc[i]<nc[min])
				min=i;
		}
		temp=min;min=-1;
		for(k=0;k<n;k++)
		if(!ch[k]&&map[temp][k])
		{
			if(ns[k]<=0)
				continue;
			if(min==-1||ns[k]<ns[min])
				min=k;
		}
		if(min==-1)
		{
			puts("NO");
			return;
		}
		mark[temp]=1;
		ch[min]=1;
		for(i=0;i<p;i++)
			if(!mark[i]&&map[i][min])
				nc[i]--;
		for(i=0;i<n;i++)
			if(!ch[i]&&map[temp][i])
				ns[i]--;
	}
	printf("YES\n");
}
void main()
{
	int i,j,t,k,h;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&p,&n);
		for(j=0;j<n;j++)
			for(k=0,ns[j]=0;k<p;k++)
				map[k][j]=0;
		for(j=0;j<p;j++)
		{
			scanf("%d",&nc[j]);
			for(k=0;k<nc[j];k++)
			{
				scanf("%d",&h);
				map[j][h-1]=1;
				ns[h-1]++;
			}	
		}
		run();
	}
}