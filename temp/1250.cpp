#include<stdio.h>
#define M 2100000000
int cost[1100][12],price[12][12][31],d[12][12];
int n,k;
void run()
{
	int i,j,h;
	for(i=0;i<=k;i++)
		for(j=0;j<n;j++)
			cost[i][j]=M;
	for(i=1;i<n;i++)
		if(price[0][i][0])
			cost[0][i]=price[0][i][0];
	for(i=0;i<k-1;i++)
		for(j=0;j<n;j++)
			if(cost[i][j]!=M)
				for(h=0;h<n;h++)
				if(h!=j&&price[j][h][(i+1)%d[j][h]])
					{
			if(cost[i+1][h]>cost[i][j]+price[j][h][(i+1)%d[j][h]])
			cost[i+1][h]=cost[i][j]+price[j][h][(i+1)%d[j][h]];
					}
	if(cost[k-1][n-1]!=M)
		printf("The best flight costs %d.\n",cost[k-1][n-1]);
	else printf("No flight possible.\n");
}
void main()
{
	int i,j,h,count=0;
	scanf("%d%d",&n,&k);
	while(n&&k)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j!=i)
				{
					scanf("%d",&d[i][j]);
					for(h=0;h<d[i][j];h++)
						scanf("%d",&price[i][j][h]);
				}
		printf("Scenario #%d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d",&n,&k);
	}
}