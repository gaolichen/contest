#include<stdio.h>
#define N 30
int cap[N],c,n,m,op[1000];
void run()
{
	int i,sum=0,max=0,mark[N];
	for(i=0;i<n;i++)
		mark[i]=0;
	for(i=0;i<m;i++)
	{
		if(mark[op[i]-1])
		{
			mark[op[i]-1]=0;
			sum-=cap[op[i]-1];
		}
		else 
		{
			mark[op[i]-1]=1;
			sum+=cap[op[i]-1];
			if(sum>c)
			{
				printf("Fuse was blown.\n");
				return;
			}
			if(sum>max)max=sum;
		}
	}
	printf("Fuse was not blown.\n");
	printf("Maximal power consumption was %d amperes.\n",max);
}
void main()
{
	int i,count=0;
	scanf("%d%d%d",&n,&m,&c);
	while(m&&n&&c)
	{
		for(i=0;i<n;i++)
			scanf("%d",&cap[i]);
		for(i=0;i<m;i++)
			scanf("%d",&op[i]);
		printf("Sequence %d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d%d",&n,&m,&c);
	}
}