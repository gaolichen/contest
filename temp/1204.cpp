#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[50],sk[50],pop,n;
int cmp(const void *i,const void *j)
{
	int *c,*d;
	c=(int *)i;
	d=(int *)j;
	return *c>*d;
}
void print(int tot)
{
	int i;
	printf("%d",a[sk[0]]);
	for(i=1;i<pop;i++)
		printf("+%d",a[sk[i]]);
	printf("=%d\n",tot);
}
int check(int tot)
{
	int top=n-1,low=0,mid;
	while(top>low+1)
	{
		mid=(top+low)/2;
		if(a[mid]>tot)
			top=mid;
		else if(a[mid]<tot)low=mid;
		else return 1;
	}
	if(a[top]==tot)return 1;
	if(a[low]==tot)
		return 1;
	return 0;
}/*
int check(int tot)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==tot)
			return 1;
		return 0;
}*/
void run()
{
	int i,k,j,find=0,tot,mark[50];
	qsort(a,n,sizeof(int),cmp);
	for(j=2;j<n;j++)
	{
		memset(mark,0,sizeof(int)*n);
		pop=i=0;tot=0;
		k=0;
		while(pop>=0)
		{
/*			if(!k&&tot>a[n-1])
			{
				pop=-1;
				j=n;
			}*/
			if(pop==j&&check(tot))
			{
				k++;
				find=1;
				print(tot);
				pop--;
				i=sk[pop]+1;
				mark[i-1]=0;
				tot-=a[i-1];
			}
			else if(tot>a[n-1]||i==n)
			{
				pop--;
				if(pop>=0)
				{
					i=sk[pop]+1;
					mark[i-1]=0;
					tot-=a[i-1];
				}
			}
			else if(!mark[i])
			{
				sk[pop++]=i;
				mark[i]=1;
				tot+=a[i++];
			}
			else i++;
		}
	}
	if(!find)
		printf("Can't find any equations.\n");
	putchar('\n');
}
void main()
{
	int i,t,now;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		run();
	}
}