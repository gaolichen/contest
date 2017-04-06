#include<stdio.h>
int count,f[28][33],e,p,i,d;
void init()
{
	int j,t=0;
	for(j=0;j<924;j++)
	{
		f[t%28][t%33]=t;
		t+=23;
	}
}
void run()
{
	int j;
	while(e-p>=28)e-=28;
	while(e-p<0)e+=28;
	while(i-p>=33)i-=33;
	while(i-p<0)i+=33;
	j=f[e-p][i-p];
	j=j-(d-p);
	if(j<=0)j+=21252;
	if(j>21252)j-=21252;
	printf("Case %d: the next triple",++count);
	printf(" peak occurs in %d days.\n",j);
}
void main()
{
	int now,t;
	init();
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		count=0;
		if(now)putchar('\n');
		scanf("%d%d%d%d",&p,&e,&i,&d);
		while(p!=-1&&e!=-1&&i!=-1&&d!=-1)
		{
		run();
		scanf("%d%d%d%d",&p,&e,&i,&d);
		}
	}
}