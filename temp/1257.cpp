#include<stdio.h>
#include<string.h>
int n,m,au[25],lea[25];
void run()
{
	int i,j,min=100,tj,mark[30],place[30];
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		place[i]=au[i];
	for(i=0;i<m;i++)
	{
		for(j=0,min=100;j<n;j++)
			if(!mark[j])
			{
				if(place[j]==lea[i])
				{
					mark[j]=lea[i];
					min=100;
					break;
				}
				else if(place[j]<lea[i]&&lea[i]-place[j]<min)
				{
					min=lea[i]-place[j];
					tj=j;
				}
				else if(place[j]>lea[i]&&lea[i]+20-place[j]<min)
				{
					min=lea[i]-place[j]+20;
					tj=j;
				}
			}
		if(min!=100)
		{
			mark[tj]=lea[i];
			for(j=0;j<n;j++)
				if(!mark[j])
					place[j]=(place[j]+min)%20;
		}
	}
	for(i=0;i<n;i++)
	{
	if(mark[i])
	printf("Original position %d parked in %d\n",au[i],mark[i]);
	else printf("Original position %d did not park\n",au[i]);
	}
}
void main()
{
	int i=0;
	while(scanf("%d",&au[i])==1)
	{
	while(au[i]!=99)
		scanf("%d",&au[++i]);
	n=i;
	i=0;
	while(scanf("%d",&lea[i])==1)
		i++;
	m=i;
	run();
	i=0;
	}
}