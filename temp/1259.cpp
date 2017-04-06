#include<stdio.h>
int n,a[1500];
void run()
{
	int i=0,j=1,sk[1500],pop=0;
	while(j<=n)
	{
		sk[pop++]=j++;
		while(pop>=1&&sk[pop-1]==a[i])
		{
			pop--;
			i++;
		}
	}
	if(i==n)
		printf("Yes\n");
	else printf("No\n");
}
void main()
{
	int i;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&a[0]);
		while(a[0])
		{
		for(i=1;i<n;i++)
			scanf("%d",&a[i]);
		run();
		scanf("%d",&a[0]);
		}
		putchar('\n');
		scanf("%d",&n);
	}
}