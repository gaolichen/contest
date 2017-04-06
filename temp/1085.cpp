#include<stdio.h>
#include<string.h>
int map[1000][1000],n,et;
void run()
{
	int i,j,sk[1000],pop,tot[1000],close,open,count=0;
	int mark[1000],room[1000];
	memset(mark,0,sizeof(mark));
	memset(tot,0,sizeof(tot));
	i=0;
	sk[0]=0;mark[0]=1;
	pop=1;
	while(pop>0)
	{
		if(sk[pop-1]==et)
		{
			for(j=0;j<pop;j++)
				tot[sk[j]]++;
			count++;
			pop--;
			if(pop>=0)
			{
				i=room[sk[pop-1]]+1;
				mark[i-1]=0;
			}
		}
		else if(i==n)
		{
			pop--;
			if(pop>=0)
			{
				i=room[sk[pop-1]]+1;
				mark[i-1]=0;
			}
		}
		else if(!mark[i]&&map[sk[pop-1]][i])
		{
			sk[pop]=i;
			room[sk[pop-1]]=i;
			mark[i]=1;
			pop++;
			i=0;
		}
		else i++;
	}
	memset(mark,0,sizeof(mark));
	mark[et]=1;
	open=close=0;sk[0]=et;
	while(open>=close)
	{
		for(i=0;i<n;i++)
			if(!mark[i]&&map[i][sk[open]])
			{
				if(tot[i]==count)
				{
					printf("Put guards in room %d.\n",i);
					return;
				}
				sk[++close]=i;
				mark[i]=1;
			}
		open++;
	}
}
void main()
{
	int i,j,t,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		if(i)printf("\n");
		scanf("%d%d",&n,&et);
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				map[j][k]=0;
		while(scanf("%d%d",&j,&k)==2)
			map[j][k]=1;
		run();
	}

}