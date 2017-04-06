/*
run1是组合数学上的算法，run2是回溯算法，当n=30，r=15时
run1用10s不到，run2要用17s
*/
#include<stdio.h>
#include<string.h>
int n,r;
void run1()
{
	int i,j=0,a[100],count=0,t;
	for(i=0;i<r;i++)
		a[i]=i+1;
	while(j>=0)
	{
//		for(i=0;i<r;i++)
//			printf("%d ",a[i]);
//		putchar('\n');
		count++;
		for(i=r-1;i>=0;i--)
			if(a[i]+1<=n&&(i==r-1||a[i+1]!=a[i]+1))
				break;
		j=i;
		if(j>=0)
		for(t=a[j];i<r;i++)
			a[i]=t+i-j+1;
	}
	printf("%d\n",count);
}
void run2()
{
	int i,sk[100],pop,count=0,j;
	pop=0;
	i=1;
	while(pop>=0)
	{
		if(pop==r)
		{
			count++;
//			for(j=0;j<r;j++)
//				printf("%d ",sk[j]);
//			putchar('\n');
			pop--;
			i=sk[pop]+1;
		}
		else if(i==n+1)
		{
			pop--;
			if(pop>=0)
				i=sk[pop]+1;
		}
		else sk[pop++]=i++;
	}
	printf("%d\n",count);
}
void main()
{
	int flag;
	while(scanf("%d%d",&n,&r)==2)
	{
		printf("choose program 1 or 2:");
		scanf("%d",&flag);
		if(flag==1) 
		run1();
		else run2();
	}
}