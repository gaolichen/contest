#include<stdio.h>
#define N 10
int pram[N],point[N][2],way[N],sk[N];
int mark[N],lev[N],tle[N],tot[N];
int p,time,a,step=0;
void copy(int k[N],int r[N])
{
	int i;
	for(i=0;i<p;i++)
		r[i]=k[i];
}
void miss()
{
	int i,j,t=0;
	tot[0]=0;
	for(i=0;i<a;i++)
		lev[i]=0;
	for(i=1;i<=p;i++)
	tot[i]=tot[i-1]+pram[sk[i-1]];
	j=1;
	for(i=0;i<a;i++)
	{
	if(point[i][1]==0)break;
	while(tot[j]<point[i][1])j++;
if(tot[j]-point[i][1]<point[i][1]-tot[j-1]||j==1)
{
	t+=tot[j]-point[i][1];
	lev[point[i][0]]+=tot[j]-point[i][1];
}
	else
	{
	t+=point[i][1]-tot[j-1];
	lev[point[i][0]]+=point[i][1]-tot[j-1];
	}
	}
	for(i=0;i<a;i++)
	{
		if(tle[i]<lev[i])
			break;
		if(tle[i]>lev[i])
		{
			copy(sk,way);
			time=t;
			for(j=0;j<a;j++)
				tle[j]=lev[j];
			break;
		}
	}
	if(i==a&&t<time)
	{
		time=t;
		copy(sk,way);
		for(j=0;j<a;j++)
			tle[j]=lev[j];
	}
}
void print()
{
	int i;
	step++;
	printf("Data set %d\n",step);
	printf("Order:");
	for(i=0;i<p;i++)
	printf(" %d",pram[way[i]]);
	printf("\nError:");
	printf(" %d\n",time);
}
void main()
{
	int i,j,t,pop;
	scanf("%d",&p);
	while(p)
	{
		for(i=0;i<p;i++)
		{scanf("%d",&pram[i]);
		mark[i]=0;}
		scanf("%d",&a);
	for(i=0;i<a;i++)
	scanf("%d%d",&point[i][0],&point[i][1]);
	for(i=0;i<a-1;i++)
		for(j=0;j<a-i-1;j++)
		{
	if(point[j][1]>point[j+1][1])
	{
	t=point[j][1];point[j][1]=point[j+1][1];
	point[j+1][1]=t;
	t=point[j][0];point[j][0]=point[j+1][0];
	point[j+1][0]=t;
	}
	}
	pop=0;i=0;
	tle[0]=2100000000;
	while(pop>=0)
	{
		if(pop==p)
		{
			miss();
			pop--;
			i=sk[pop]+1;
			mark[i-1]=0;
		}
		else if(i==p)
		{
			pop--;
			if(pop>=0)
			{
				i=sk[pop]+1;
			    mark[sk[pop]]=0;
			}
		}
		else if(!mark[i])
		{
			sk[pop]=i;
			mark[i]=1;
			pop++;
			i=0;
		}
		else i++;
	}
	print();
	scanf("%d",&p);
	}
}