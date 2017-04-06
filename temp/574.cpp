#include<stdio.h>
#define N 200
int a[N],sk[N],temp[N],mark[N],pop,step,t,n;
void print()
{
	int i,flag=1;
	for(i=0;i<pop;i++)
		if(temp[i]==-1||a[temp[i]]!=a[sk[i]])break;
	if(i==pop)flag=0;
	if(!step)step=1;
	if(flag)
	{
	for(i=0;i<pop;i++)
	{
		if(!i)
		printf("%d",a[sk[i]]);
		else if(a[sk[i]]>=0)
			printf("+%d",a[sk[i]]);
		else printf("+(%d)",a[sk[i]]);
	}
	printf("\n");
	for(i=0;i<pop;i++)
		temp[i]=sk[i];
	}
}
void main()
{
	int i,tot;
	scanf("%d%d",&t,&n);
	while(n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mark[i]=0;
			temp[i]=-1;
		}
		printf("Sums of %d:\n",t);
		pop=i=tot=step=0;
		while(pop>=0)
		{
			if(tot==t)
			{
				print();
				pop--;
				if(pop>=0)
				{
				i=sk[pop]+1;
				mark[i-1]=0;
				tot-=a[i-1];
				}
			}
			else if(pop==n)
			{
				pop--;
				if(pop>=0)
				{
					i=sk[pop]+1;
					mark[i-1]=0;
					tot-=a[i-1];
				}
			}
			else if(i==n)
			{
				pop--;
				if(pop>=0)
				{
				i=sk[pop]+1;
				mark[i-1]=0;
				tot-=a[i-1];
				}
			}
			else if(!mark[i])
			{
				sk[pop]=i;
				mark[i]=1;
				tot+=a[i];
				pop++;
				i++;
			}
			else i++;
		}
		if(!step)
			printf("NONE\n");
		scanf("%d%d",&t,&n);
	}
}