#include<stdio.h>
#include<string.h>
int pc[36],h[36],e[36],k[36],d[36],b[36],count;
int th,te,tk,td,tb,tp;
char sp[36][3];
int n;
void run()
{
	int i,j,mark[36],min;
	memset(mark,0,sizeof(mark));
	printf("Player  Hit Pct    KPG      BPG      DPG\n");
	printf("-----------------------------------------\n");
	for(i=0;i<count;i++)
	{
		min=-1;
		for(j=0;j<count;j++)
			if(!mark[j]&&(min==-1||strcmp(sp[j],sp[min])<0))
				min=j;
		printf("%s      ",sp[min]);
		if(k[min]+e[min]+h[min]==0)
			printf("+0.000   ");
		else 
		{
			if(k[min]-e[min]>=0)putchar('+');
	printf("%.3lf   ",(double)(k[min]-e[min])/(k[min]+e[min]+h[min]));
		}
		if(pc[min]==0)
			printf(" 0.000    0.000    0.000\n");
		else 
		{
			printf("%6.3lf   ",k[min]/(double)pc[min]);
			printf("%6.3lf   ",b[min]/(double)pc[min]);
			printf("%6.3lf\n",d[min]/(double)pc[min]);
		}
		mark[min]=1;
	}
	printf("team    ");
	if(th+tk+te==0)
		printf("+0.000   ");
	else
	{
		if(tk-te>=0)putchar('+');
		printf("%.3lf   ",(double)(tk-te)/(tk+te+th));
	}
	if(tp==0)
		printf(" 0.000    0.000    0.000\n");
	else 
	{
		printf("%6.3lf   ",tk/(double)tp);
		printf("%6.3lf   ",tb/(double)tp);
		printf("%6.3lf\n",td/(double)tp);
	}
}
void main()
{
	int i,flag=1,j;
	char str[3],tsp[3];
	scanf("%s",str);
	while(1)
	{
		scanf("%d",&n);
		if(flag)
		{
		memset(pc,0,sizeof(pc));
		memset(b,0,sizeof(b));
		memset(k,0,sizeof(k));
		memset(h,0,sizeof(h));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		flag=0;count=0;
		tp=tb=tk=th=td=te=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(j=0;j<count;j++)
				if(strcmp(str,sp[j])==0)
					break;
			if(j==count)
				strcpy(sp[count++],str);
			pc[j]++;
		}
		tp++;
		while(1)
		{
			scanf("%s",str);
			if(str[0]=='R')
			{flag=1;break;}
			if(str[0]=='C')
				break;
			scanf("%s",tsp);
			for(i=0;i<count;i++)
				if(strcmp(tsp,sp[i])==0)
				{
					if(str[0]=='H')
					{h[i]++;th++;}
					if(str[0]=='B')
					{b[i]++;tb++;}
					if(str[0]=='E')
					{e[i]++;te++;}
					if(str[0]=='D')
					{d[i]++;td++;}
					if(str[0]=='K')
					{k[i]++;tk++;};
					break;
				}
		}
		if(flag)
		{
			run();
			putchar('\n');
			if(scanf("%s",str)!=1)
				return;
		}
	}
}