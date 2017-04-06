#include<stdio.h>
#include<string.h>
int res[30000],num[30000];
int n,k;
void run()
{
	int i,j,count=2100000000,tot;
	for(i=1;i<10;i++)
	{
		tot=0;j=0;
		num[0]=(i*k)%10;j=(i*k)/10;
		while(j||num[tot]!=i)
		{
			num[tot+1]=(num[tot]*k+j)%10;
			j=(num[tot]*k+j)/10;
			tot++;
		}
		if(count>tot)
			for(count=tot,j=0;j<=tot;j++)
				res[j]=num[j];
		else if(count==tot)
		{
			for(j=tot;j>=0;j--)
				if(res[j]!=num[j])break;
			if(j<0)continue;
			if(res[j]<num[j])continue;
			for(j=0;j<=tot;j++)
				res[j]=num[j];
		}
	}
	for(i=count;i>=0;i--)
		printf("%d",res[i]);
	putchar('\n');
}
void main()
{
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		if(i)
			putchar('\n');
		scanf("%d",&k);
		run();
	}
}