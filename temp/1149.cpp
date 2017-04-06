#include<stdio.h>
#include<string.h>
int mar[300000],num[6],zhi[300000];
void run()
{
	int i,j,k,t,tot=0,count=0;
	for(i=0;i<6;i++)
		tot+=(i+1)*num[i];
	if(tot%2)
	{
		printf("Can't be divided.\n\n");
		return;
	}
	tot/=2;
	memset(mar,0,sizeof(int)*tot);
	for(i=0;i<5;i++)
		if(num[i])break;
	for(j=0;j<=num[i];j++)
	{
		if(j*(i+1)>tot)
			break;
		if(j*(i+1)==tot)
		{
			printf("Can be divided.\n\n");
			return;
		}
		mar[j*(i+1)]=1;
		zhi[count++]=j*(i+1);
	}
	for(i++;i<6;i++)
	{
		t=count;
		if(num[i])
		for(j=1;j<=num[i];j++)
			for(k=0;k<t;k++)
			{
				if(zhi[k]+j*(i+1)>tot)continue;
				if(zhi[k]+j*(i+1)==tot)
				{
					printf("Can be divided.\n\n");
					return;
				}
				if(mar[zhi[k]+j*(i+1)])continue;
				zhi[count++]=zhi[k]+j*(i+1);
				mar[zhi[k]+j*(i+1)]=1;
			}
	}
	printf("Can't be divided.\n\n");
}
void main()
{
	int i,count=0;
	for(i=0;i<6;i++)
		scanf("%d",&num[i]);
	while(num[0]||num[1]||num[2]||num[3]||num[4]||num[5])
	{
		printf("Collection #%d:\n",++count);
		run();
		for(i=0;i<6;i++)
			scanf("%d",&num[i]);
	}
}