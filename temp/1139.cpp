#include<stdio.h>
#include<string.h>
#define N 60000
int x1[N],y1[N],x2[N],y2[N];
int n;
int check(int a,int b)
{
	if(x1[a]<x1[b]||x2[a]>x2[b])
		return 0;
	if(y1[a]<y1[b]||y2[a]>y2[b])
		return 0;
	return 1;
}
void run()
{
	int i,j,tot=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(j!=i&&check(i,j))
			{
				tot++;
				break;
			}
	printf("%d\n",tot);
}
void main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
	scanf("%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i]);
		run();
	}
}