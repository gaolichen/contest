#include<stdio.h>
void main()
{
	int i,n,tot,min,count=0,sk[100];
	scanf("%d",&n);
	while(n)
	{
		tot=min=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&sk[i]);
			tot+=sk[i];
		}
		tot/=n;
		for(i=0;i<n;i++)
			if(sk[i]>tot)
				min+=sk[i]-tot;
		printf("Set #%d\n",++count);
		printf("The minimum number of moves is %d.\n\n",min);
		scanf("%d",&n);
	}
}