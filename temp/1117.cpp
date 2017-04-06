#include<stdio.h>
#include<string.h>
int step[100],mark[100],cap[100],last[100][2],sk[100];
char str[10000];
void run()
{
	int i,j,k,min1,min2,len,count,tot,sum,open,close;
	len=strlen(str);
	memset(cap,0,sizeof(cap));
	memset(mark,0,sizeof(mark));
	memset(last,-1,sizeof(last));
	for(i=0;i<len;i++)
	{
		if(str[i]=='_')
			cap[26]++;
		else cap[str[i]-'A']++;
	}
	for(i=0,j=0;i<27;i++)
		if(cap[i])
			cap[j++]=cap[i];
	if(j==1)
	{
		printf("%d %d 8.0\n",len*8,len);
		return;
	}
	count=tot=j;
	do
	{
		min1=min2=-1;
		for(k=0;k<tot;k++)
			if(cap[k]&&!mark[k]&&(min1==-1||cap[k]<cap[min1]))
				min1=k;
		if(min1!=-1)mark[min1]=1;
		for(k=0;k<tot;k++)
			if(cap[k]&&!mark[k]&&(min2==-1||cap[k]<cap[min2]))
				min2=k;
		if(min2!=-1)mark[min2]=1;
		if(min1!=-1&&min2!=-1)
		{
		cap[tot]=cap[min1]+cap[min2];
		last[tot][0]=min1;
		last[tot++][1]=min2;
		}
	}while(min1!=-1&&min2!=-1);
	open=close=0;
	sk[open]=tot-1;step[tot-1]=0;
	while(open<=close)
	{
		for(i=0;i<2;i++)
			if(last[sk[open]][i]!=-1)
			{
				sk[++close]=last[sk[open]][i];
				step[sk[close]]=step[sk[open]]+1;	
			}
		open++;
	}
	sum=0;
	for(i=0;i<count;i++)
		sum+=step[i]*cap[i];
	printf("%d %d %.1lf\n",len*8,sum,len*8.0/sum);
}
void main()
{
	scanf("%s",str);
	while(strcmp(str,"END")!=0)
	{
		run();
		scanf("%s",str);
	}
}